#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :QMainWindow(parent)
{
	ui.setupUi(this);

	qRegisterMetaType<Command>("Command");
	ElevatorStopped = 1;

	ui.textBrowser->setText("System Start!");
	setWindowTitle("Main Window");

	eui = new ElevatorUserInterface(this);
	bi = new BuildingInterface(this);

	elevator = new Elevator();
	ElevatorThread = new QThread();
	ElevatorInterfaceThread = new QThread();
	Floor1Thread = new QThread();
	Floor2Thread = new QThread();
	Floor3Thread = new QThread();
	Floor4Thread = new QThread();
	ElevatorInterfaceObject = new InterfaceInteract();
	Floor1Object = new InterfaceInteract();
	Floor2Object = new InterfaceInteract();
	Floor3Object = new InterfaceInteract();
	Floor4Object = new InterfaceInteract();

	QObject::connect(eui, &ElevatorUserInterface::SendCommand, ElevatorInterfaceObject, &InterfaceInteract::ReceiveCommand);
	QObject::connect(bi, &BuildingInterface::SendToThread1, Floor1Object, &InterfaceInteract::ReceiveCommand);
	QObject::connect(bi, &BuildingInterface::SendToThread2, Floor2Object, &InterfaceInteract::ReceiveCommand);
	QObject::connect(bi, &BuildingInterface::SendToThread3, Floor3Object, &InterfaceInteract::ReceiveCommand);
	QObject::connect(bi, &BuildingInterface::SendToThread4, Floor4Object, &InterfaceInteract::ReceiveCommand);
	QObject::connect(ElevatorInterfaceObject, &InterfaceInteract::SendCommand, this, &MainWindow::ReceiveCommand);
	QObject::connect(Floor1Object, &InterfaceInteract::SendCommand, this, &MainWindow::ReceiveCommand);
	QObject::connect(Floor2Object, &InterfaceInteract::SendCommand, this, &MainWindow::ReceiveCommand);
	QObject::connect(Floor3Object, &InterfaceInteract::SendCommand, this, &MainWindow::ReceiveCommand);
	QObject::connect(Floor4Object, &InterfaceInteract::SendCommand, this, &MainWindow::ReceiveCommand);
	QObject::connect(this, &MainWindow::ElevatorStart, elevator, &Elevator::ReceiveCommand);
	QObject::connect(elevator, &Elevator::SendElevatorStatus, this, &MainWindow::ReceiveElevatorStatus);
	QObject::connect(elevator, &Elevator::Ready, this, &MainWindow::GiveCommand);
	QObject::connect(ElevatorThread, &QThread::finished, elevator, &QObject::deleteLater);

	eui->show();
	bi->show();
	elevator->moveToThread(ElevatorThread);
	ElevatorInterfaceObject->moveToThread(ElevatorInterfaceThread);
	Floor1Object->moveToThread(Floor1Thread);
	Floor2Object->moveToThread(Floor2Thread);
	Floor3Object->moveToThread(Floor3Thread);
	Floor4Object->moveToThread(Floor4Thread);
	ElevatorThread->start();
	ElevatorInterfaceThread->start();
	Floor1Thread->start();
	Floor2Thread->start();
	Floor3Thread->start();
	Floor4Thread->start();
}

void MainWindow::ReceiveCommand(Command c)
{
	Commands.insert(c);
	if (ElevatorStopped)
	{
		GiveCommand(Position, Status);
	}
}

void MainWindow::ReceiveElevatorStatus(int position, int status, int door_status)
{
	ui.lineEdit->setText(QString::number(position));
	if (status == 0)
	{
		ui.Direction->setText("Elevator Stopped");
	}
	else if (status == 1)
	{
		ui.Direction->setText("Moving Upward");
	}
	else if (status == 2)
	{
		ui.Direction->setText("Moving Downward");
	}
	if (door_status)
	{
		ui.textBrowser->setText("Door Open");
	}
	else
	{
		ui.textBrowser->setText("Door Closed");
	}
}

void MainWindow::GiveCommand(int position, int status)
{
	Position = position;
	Status = status;
	if (Commands.empty())
	{
		ElevatorStopped = 1;
	}
	else
	{
		ElevatorStopped = 0;
		int move = 0;
		bool open = 0;
		bool erase_flag = 0;
		for (auto it = Commands.begin(); it != Commands.end();)
		{
			erase_flag = 0;
			if ((*it).CommandType == OPEN)
			{
				open = 1;
				erase_flag = 1;
			}
			else if ((*it).CommandType == MOVE_TO_COMMAND)
			{
				if ((*it).Destination > Position && status != MOVING_DOWN)
				{
					move = MOVING_UP;
				}
				else if ((*it).Destination < Position && status != MOVING_UP)
				{
					move = MOVING_DOWN;
				}
				else if ((*it).Destination == position)
				{
					open = 1;
					erase_flag = 1;
				}
			}
			if (erase_flag)
			{
				auto temp = it;
				temp++;
				Commands.erase(it);
				it = temp;
			}
			else
			{
				it++;
			}
		}
		if (open)
		{
			emit ElevatorStart(STILL);
		}
		if (move)
		{
			emit ElevatorStart(move);
		}
		else
		{
			emit ElevatorStart(STOP);
		}
	}
}
