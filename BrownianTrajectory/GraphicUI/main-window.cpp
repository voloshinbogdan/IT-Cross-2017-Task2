#include "main-window.h"

#include <cassert>

#include <QPainter>
#include <QPixmap>
#include <QResizeEvent>
#include <QPen>
#include <QRect>
#include <QFont>
#include <QWidget>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QTranslator>



MainWindow::MainWindow(QWidget *pParent)
	: QMainWindow(pParent)
{
	
	path = generate_path(delta_time, step_count, v_max, last_angle, last_v);
	setAttribute(Qt::WA_NoSystemBackground, true);

	uidp = new Ui_DataPane;
	dataPane = new QDialog;
	uidp->setupUi(dataPane);
	connect(
		dataPane, &QDialog::accepted,
		this, &MainWindow::refreshParameters);

	Ui_About uia;
	about = new QDialog;
	uia.setupUi(about);

	createActions();
	createMenus();
}



void MainWindow::refreshParameters()
{
	delta_time = uidp->doubleSpinBox_dtime->value();
	step_count = uidp->spinBox_stepc->value();
	v_max = uidp->doubleSpinBox_maxv->value();

	path = generate_path(delta_time, step_count, v_max, last_angle, last_v);
	reDraw(this->size());

	this->repaint();
}



void MainWindow::createActions()
{
	exitAct = new QAction("&Exit", this);
	connect(exitAct, &QAction::triggered, this, &MainWindow::appExit);

	dataPaneAct = new QAction("&Data pane", this);
	connect(dataPaneAct, &QAction::triggered, this, &MainWindow::openDataPane);

	aboutAct = new QAction("&About", this);
	connect(aboutAct, &QAction::triggered,  this, &MainWindow::openAbout);
}



void MainWindow::createMenus()
{
	fileMenu = menuBar()->addMenu("&File");
	fileMenu->addAction(exitAct);

	editMenu = menuBar()->addMenu("&Edit");
	editMenu->addAction(dataPaneAct);

	helpMenu = menuBar()->addMenu("&Help");
	helpMenu->addAction(aboutAct);
}



void MainWindow::appExit()
{
	close();
}



void MainWindow::openDataPane()
{
	uidp->doubleSpinBox_dtime->setValue(delta_time);
	uidp->spinBox_stepc->setValue(step_count);
	uidp->doubleSpinBox_maxv->setValue(v_max);
	dataPane->show();
}



void MainWindow::openAbout()
{
	about->show();
}



void MainWindow::reDraw(const QSize &size)
{
	m_Pixmap = QPixmap(size);
	m_Pixmap.fill(Qt::white);

	QPainter painter(&m_Pixmap);

	std::vector<point> points = rescalePoints(path, size);

	for(int i = 1; i < path.size(); ++i) {
		painter.drawLine(
			points[i - 1].x, points[i - 1].y,
			points[i].x, points[i].y);
	}

	const QString start = QString::fromLocal8Bit(
			"Start");
	painter.drawText(points[0].x, points[0].y, start);

	const QString m = QString::fromLocal8Bit(
			"(") + QString::number(last_v, 'g', 2) + ";" + QString::number(last_angle, 'g', 2) + ")";
	painter.drawText(points[path.size()-1].x, points[path.size()-1].y, m);
}



void MainWindow::resizeEvent(QResizeEvent *pEvent)
{
	reDraw(pEvent->size());
	/*
	const QString cstrL = QString::fromLocal8Bit(
			"Upper-Left Corner");
	painter.drawText(10, 10, cstrL);

	painter.drawLine(10, 10, 100, 100);
	QFont font("Arial", 24);
	font.setUnderline(true);

	const QString cstrC = QString::fromLocal8Bit("Center");
	const int cnFlags = Qt::AlignCenter | Qt::TextSingleLine;
	QRect rectText;
	painter.setFont(font);
	painter.drawText(m_Pixmap.rect(), cnFlags, cstrC, &rectText);
	rectText.adjust(-20, -20, 20, 20);
	QPen pen(QColor(50, 200, 50));
	pen.setStyle(Qt::DashLine);
	pen.setWidth(5);
	painter.setPen(pen);
	painter.drawRect(rectText);
	*/
}



void MainWindow::paintEvent(QPaintEvent *pEvent)
{
	QPainter painter(this);
	painter.drawPixmap(0, 0, m_Pixmap);
}



std::vector<point> MainWindow::rescalePoints(std::vector<point> &points, const QSize& size)
{
	// Process start point
	std::vector<point> newPoints;

	double xCenter = size.width() / 2;
	double yCenter = (size.height()) / 2;

	for(int i = 0; i < points.size(); ++i) {
		newPoints.push_back(point(
			points[i].x - points[0].x,
			points[i].y - points[0].y));
	}

	// Process scale
	double maxX = 0;
	double maxY = 0;

	for(int i = 0; i < newPoints.size(); ++i) {
		point centeredDistance(abs(newPoints[i].x), abs(newPoints[i].y));
		if (centeredDistance.x > maxX) {
			maxX = centeredDistance.x;
		}
		if (centeredDistance.y > maxY) {
			maxY = centeredDistance.y;
		}
	}

	double scale = std::min(0.9 * xCenter / maxX, 0.9 * yCenter / maxY);
	for(int i = 0; i < newPoints.size(); ++i) {
		newPoints[i].x *= scale;
		newPoints[i].y *= scale;
	}

	double dx = xCenter - newPoints[0].x;
	double dy = yCenter - newPoints[0].y;


	for(int i = 0; i < points.size(); ++i) {
		newPoints[i].x += xCenter;
		newPoints[i].y += yCenter;
	}

	return newPoints;
}



