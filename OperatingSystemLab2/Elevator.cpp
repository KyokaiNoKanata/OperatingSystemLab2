#include "Elevator.h"

Elevator::Elevator()
{

	Position = 0;
	Status = 0;
	DoorStatus = DOOR_CLOSE;
}

void Elevator::ElevatorRun()
{
	qDebug() << "a";
}

void Elevator::move(int direction)
{
	if (direction == UP)
	{
		QThread::sleep(1);
		Position++;
	}
	else
	{
		QThread::sleep(1);
		Position--;
	}
}

void Elevator::DoorOpen()
{
	DoorStatus = DOOR_OPEN;
	emit SendElevatorStatus(Position, Status, DoorStatus);
	QThread::sleep(1);
	emit SendElevatorStatus(Position, Status, DoorStatus);
	DoorStatus = DOOR_CLOSE;
}

void Elevator::ReceriveCommand(Command c)
{
	//emit SendElevatorStatus();
	switch (c.CommandType)
	{
	case OPEN:
		DoorOpen();
		break;
	case CLOSE:
		break;
	default:
		Commands.insert(c);
		break;
	}
	emit SendElevatorStatus(Position, Status, DoorStatus);
}