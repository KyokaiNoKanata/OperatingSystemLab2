#pragma once

#include <vector>
#include <set>
#include <QObject>
#include <QThread>
#include <QDebug>
#include "Command.h"

#define STILL 0
#define MOVING_UP 1
#define MOVING_DOWN 2
#define DOOR_CLOSE 0
#define DOOR_OPEN 1
#define UP 1
#define DOWN 0
#define STOP 3

class Elevator :public QObject
{
	Q_OBJECT
public:
	Elevator();
	void ElevatorRun();

signals:
	void SendElevatorStatus(int position, int status, int door_status);
	void Ready(int floor, int status);

; public slots:
	void ReceiveCommand(int c);
	void Update();

private:
	int Position;
	int Status;
	int DoorStatus;
	void Move(int direction);
	void DoorOpen();
};
