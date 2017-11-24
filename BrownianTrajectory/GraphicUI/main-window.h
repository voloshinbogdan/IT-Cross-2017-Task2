#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QSize>
#include <vector>
#include <QMainWindow>
#include <QDialog>

#include <BrownianTrajectoryLib.h>
#include "ui_data_pane.h"
#include "ui_about.h"

class QAction;
class QMenu;


class MainWindow : public QMainWindow
{
public:

	MainWindow(QWidget *pParent = 0);

protected:
	void resizeEvent(QResizeEvent *pEvent);
	void paintEvent(QPaintEvent *pEvent);
	void reDraw(const QSize &size);

private slots:
	void appExit();
	void openDataPane();
	void openAbout();
private:

	void refreshParameters();
	void createActions();
	void createMenus();

	QMenu *fileMenu;
	QMenu *editMenu;
	QMenu *helpMenu;
	QAction *exitAct;
	QAction *dataPaneAct;
	QAction *aboutAct;

	QDialog *about;
	QDialog *dataPane;
	Ui_DataPane *uidp;
	std::vector<point> rescalePoints(std::vector<point> &points, const QSize& size);

	QPixmap m_Pixmap;
	double delta_time = 2;
	int step_count = 10;
	double v_max = 5;
	double last_angle;
	double last_v;
	std::vector<point> path;
}; // class MainWindow

#endif // MAIN_WINDOW_H
