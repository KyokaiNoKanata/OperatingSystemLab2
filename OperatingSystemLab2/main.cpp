#include <QtWidgets/QApplication>

#include "MainWindow.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.setWindowTitle("Ö÷½çÃæ");
	w.show();
	return a.exec();
}
