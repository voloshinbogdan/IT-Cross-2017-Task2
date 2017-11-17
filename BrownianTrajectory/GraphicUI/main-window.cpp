#include "main-window.h"

#include <QPainter>
#include <QPixmap>
#include <QResizeEvent>
#include <QPen>
#include <QRect>
#include <QFont>
#include <QWidget>



MainWindow::MainWindow(QWidget *pParent)
	: QWidget(pParent)
{
	setAttribute(Qt::WA_NoSystemBackground, true);
}



void MainWindow::resizeEvent(QResizeEvent *pEvent)
{
	m_Pixmap = QPixmap(pEvent->size());
	m_Pixmap.fill(Qt::white);

	QPainter painter(&m_Pixmap);

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
}



void MainWindow::paintEvent(QPaintEvent *pEvent)
{
	QPainter painter(this);
	painter.drawPixmap(0, 0, m_Pixmap);
}



void MainWindow::rescalePoints(std::vector<points> &points, const QSize& size)
{
	// Process start point
	int xCenter = size.width() / 2;
	int yCenter = size.height() / 2;

	int dx = xCenter - points[0].x;
	int dy = yCenter - points[0].y;

	for(int i = 0; i < points.size(); ++i) {
		points[i].x += dx;
		points[i].y += dy;
	}

	// Process scale
	double max_x = 0;
	double max_y = 0;


}



