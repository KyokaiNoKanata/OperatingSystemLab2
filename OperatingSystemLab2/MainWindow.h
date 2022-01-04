#pragma once

#include <QtWidgets/QMainWindow>
#include <QObject>
#include <set>
#include <QTimer>
#include <algorithm>

#include "ui_MainWindow.h"
#include "Command.h"
#include "Elevator.h"
#include "ElevatorUserInterface.h"

class MainWindow :public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = Q_NULLPTR);

signals:
	void ElevatorStart(int c);

public slots:
	void ReceiveCommand(Command c);
	void ReceiveElevatorStatus(int position, int status, int door_status);
	void GiveCommand(int postion, int status);

private:
	Ui::MainWindowClass ui;
	ElevatorUserInterface* eui;
	Elevator* elevator;
	QThread* ElevatorThread;
	QTimer* timer;
	std::set<Command>Commands;
	bool ElevatorStopped;
	int Position;
	int Status;
};
