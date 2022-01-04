#include "Elevator.h"

Elevator::Elevator()
{
	Position = 0;
	Status = STILL;
	DoorStatus = DOOR_CLOSE;
}

void Elevator::ElevatorRun()
{
	qDebug() << "a";
}

void Elevator::Update()
{
	qDebug() << DoorStatus;
	emit SendElevatorStatus(Position, Status, DoorStatus);
}

void Elevator::Move(int direction)
{
	Update();
	if (direction == UP)
	{
		Status = MOVING_UP;
		QThread::sleep(1);
		Position++;
	}
	else
	{
		Status = MOVING_DOWN;
		QThread::sleep(1);
		Position--;
	}
}

void Elevator::DoorOpen()
{
	DoorStatus = DOOR_OPEN;
	Update();
	QThread::sleep(1);
	DoorStatus = DOOR_CLOSE;
}

void Elevator::ReceiveCommand(int c)
{
	Update();
	switch (c)
	{
	case(STILL):
		DoorOpen();
		break;
	case(MOVING_UP):
		Move(UP);
		break;
	case(MOVING_DOWN):
		Move(DOWN);
		break;
	case(STOP):
		Status = STILL;
		break;
	}
	Update();
	Ready(Position, Status);
}