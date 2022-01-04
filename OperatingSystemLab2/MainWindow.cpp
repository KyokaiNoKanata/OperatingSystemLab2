#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle("Main Window");
	eui = new ElevatorUserInterface(this);
	connect(eui, SIGNAL(SendCommand(QString)), this, SLOT(ReceiveMessage(QString)));
	eui->show();
	ui.textBrowser->setText("System Start!");
}

void MainWindow::ReceiveMessage(QString qs)
{
	ui.textBrowser->setText(qs);
}