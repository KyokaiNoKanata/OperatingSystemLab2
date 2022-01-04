#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :QMainWindow(parent)
{
	ui.setupUi(this);
	ui.textBrowser->setText("System Start!");
	setWindowTitle("Main Window");
	eui = new ElevatorUserInterface(this);
	elevator = new Elevator();
	ElevatorThread = new QThread();
	qRegisterMetaType<Command>("Command");
	QObject::connect(eui, &ElevatorUserInterface::SendCommand, elevator, &Elevator::ReceriveCommand);
	//QObject::connect(eui, &ElevatorUserInterface::SendCommand, this, &MainWindow::ReceiveMessage);
	QObject::connect(elevator, &Elevator::SendElevatorStatus, this, &MainWindow::ReceiveElevatorStatus);
	connect(ElevatorThread, &QThread::finished, elevator, &QObject::deleteLater);
	elevator->moveToThread(ElevatorThread);
	ElevatorThread->start();
	eui->show();
	//qDebug() << "a";
}

void MainWindow::ReceiveMessage(Command c)
{
	ui.textBrowser->setText(QString::number(c.CommandType));
}

void MainWindow::ReceiveElevatorStatus(int position, int status, int door_status)
{
	ui.lineEdit->setText(QString::number(position));
	ui.Direction->setText(QString::number(status));
	ui.textBrowser->setText(QString::number(door_status));
}
