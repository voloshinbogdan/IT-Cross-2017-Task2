#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QSize>
#include <vector>

#include <BrownianTrajectoryLib.h>

class MainWindow : public QWidget
{
public:

	MainWindow(QWidget *pParent = 0);

protected:

	void resizeEvent(QResizeEvent *pEvent);
	void paintEvent(QPaintEvent *pEvent);

private:
	std::vector<point> rescalePoints(std::vector<point> &points, const QSize& size);

	QPixmap m_Pixmap;
	double delta_time = 2;
	int step_count = 10;
	double v_max = 5;
	std::vector<point> path;
}; // class MainWindow

#endif // MAIN_WINDOW_H
