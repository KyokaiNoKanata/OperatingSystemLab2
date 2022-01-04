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
#include "BuildingInterface.h"
#include "InterfaceInteract.h"

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
	BuildingInterface* bi;
	Elevator* elevator;
	QThread* ElevatorThread;
	QThread* ElevatorInterfaceThread;
	InterfaceInteract* ElevatorInterfaceObject;
	QThread* Floor1Thread;
	QThread* Floor2Thread;
	QThread* Floor3Thread;
	QThread* Floor4Thread;
	InterfaceInteract* Floor1Object;
	InterfaceInteract* Floor2Object;
	InterfaceInteract* Floor3Object;
	InterfaceInteract* Floor4Object;
	QTimer* timer;
	std::set<Command>Commands;
	bool ElevatorStopped;
	int Position;
	int Status;
};
