#include "main-window.h"

#include <QApplication>



int main(int nArgC, char *apszArgV[]) {
	QApplication app(nArgC, apszArgV);
	MainWindow *pWindow = new MainWindow;
	pWindow->show();

	return app.exec();
}
