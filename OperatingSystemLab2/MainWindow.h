#pragma once

#include <QtWidgets/QMainWindow>
#include <QObject>
#include <vector>

#include "ui_MainWindow.h"
#include "Command.h"
#include "Elevator.h"
#include "ElevatorUserInterface.h"

class MainWindow :public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = Q_NULLPTR);

public slots:
	void ReceiveMessage(Command c);
	void ReceiveElevatorStatus(int position, int status, int door_status);

private:
	Ui::MainWindowClass ui;
	ElevatorUserInterface* eui;
	Elevator* elevator;
	QThread* ElevatorThread;
};
