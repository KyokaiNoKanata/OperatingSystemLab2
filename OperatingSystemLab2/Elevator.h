#pragma once

#include <vector>
#include <set>
#include <QObject>
#include <QThread>
#include <QDebug>
#include "Command.h"

class Elevator :public QObject
{
	Q_OBJECT
public:
	Elevator();

signals:
	void SendElevatorStatus(int position, int status, int door_status);
	void Ready(int floor, int status);

public slots:
	void ReceiveCommand(int c);
	void Update();

private:
	int Position;
	int Status;
	int DoorStatus;
	void Move(int direction);
	void DoorOpen();
};
