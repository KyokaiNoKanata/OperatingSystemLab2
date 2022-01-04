#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :QMainWindow(parent)
{
	ui.setupUi(this);
	ElevatorStopped = 1;
	ui.textBrowser->setText("System Start!");
	setWindowTitle("Main Window");
	eui = new ElevatorUserInterface(this);
	elevator = new Elevator();
	ElevatorThread = new QThread();
	qRegisterMetaType<Command>("Command");
	QObject::connect(eui, &ElevatorUserInterface::SendCommand, this, &MainWindow::ReceiveCommand);
	QObject::connect(this, &MainWindow::ElevatorStart, elevator, &Elevator::ReceiveCommand);
	QObject::connect(elevator, &Elevator::SendElevatorStatus, this, &MainWindow::ReceiveElevatorStatus);
	QObject::connect(elevator, &Elevator::Ready, this, &MainWindow::GiveCommand);
	QObject::connect(ElevatorThread, &QThread::finished, elevator, &QObject::deleteLater);
	elevator->moveToThread(ElevatorThread);
	ElevatorThread->start();
	eui->show();
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
	ui.Direction->setText(QString::number(status));
	ui.textBrowser->setText(QString::number(door_status));
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
		int move = 0;
		bool open = 0;
		bool direction_flag = 0;
		int max_floor = 0;
		int min_floor = 5;
		bool erase_flag = 0;
		for (auto it = Commands.begin(); it != Commands.end(); it++)
		{
			max_floor = std::max(max_floor, (*it).Destination);
			min_floor = std::min(min_floor, (*it).Destination);
		}
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
				if ((*it).Direction == STILL || (*it).Direction == Status || Status == STILL)
				{
					direction_flag = 1;
				}
				if ((*it).Destination > Position && status != MOVING_DOWN)
				{
					if (direction_flag)
					{
						move = MOVING_UP;
					}
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
