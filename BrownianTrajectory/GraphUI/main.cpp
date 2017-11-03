#include <QApplication>
#include <QLabel>

int main(int nArgC, char *apszArgV[]) {
	QApplication app(nArgC, apszArgV);
	QLabel *pLabel = new QLabel("Hello Qt!");
	pLabel->show();

	return app.exec();
}
