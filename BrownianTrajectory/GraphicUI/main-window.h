#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>

class MainWindow : public QWidget
{
public:

	MainWindow(QWidget *pParent = 0);

protected:

	void resizeEvent(QResizeEvent *pEvent);
	void paintEvent(QPaintEvent *pEvent);

private:

	QPixmap m_Pixmap;
}; // class MainWindow

#endif // MAIN_WINDOW_H
