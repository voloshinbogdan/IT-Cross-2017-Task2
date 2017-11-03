#include "main-window.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *pParent)
	: QWidget(pParent)
{
	setAttribute(Qt::WA_NoSystemBackground, true);
}

void MainWindow:resizeEvent(QResizeEvent *pEvent)
{
	m_Pixmap = QPixmap(pEvent->size());
	m_Pixmap.fill(Qt::white);

	QPainter painter(
