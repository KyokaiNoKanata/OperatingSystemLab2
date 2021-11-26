#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ElevatorUserInterface1 = new ElevatorUserInterface();
	ElevatorUserInterface1->show();
}
