#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QSize>
#include <vector>
#include <QMainWindow>
#include <QDialog>

#include <BrownianTrajectoryLib.h>
#include "ui_data_pane.h"

class QAction;
class QMenu;


class MainWindow : public QMainWindow
{
Q_OBJECT
public:

	MainWindow(QWidget *pParent = 0);

protected:
	void resizeEvent(QResizeEvent *pEvent);
	void paintEvent(QPaintEvent *pEvent);

private slots:
	void appExit();
	void openDataPane();
	void openAbout();
public slots:
	void refreshParameters();
private:

	void createActions();
	void createMenus();

	QMenu *fileMenu;
	QMenu *editMenu;
	QMenu *helpMenu;
	QAction *exitAct;
	QAction *dataPaneAct;
	QAction *aboutAct;

	QDialog *dataPane;
	Ui_DataPane *uidp;
	std::vector<point> rescalePoints(std::vector<point> &points, const QSize& size);

	QPixmap m_Pixmap;
	double delta_time = 2;
	int step_count = 10;
	double v_max = 5;
	std::vector<point> path;
}; // class MainWindow

#endif // MAIN_WINDOW_H
