#include "ElevatorUserInterface.h"

ElevatorUserInterface::ElevatorUserInterface(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	command = new Command(0, 0, 0, 0);
	connect(ui.Open, SIGNAL(clicked()), this, SLOT(ElevatorOpen()));
	connect(ui.Close, SIGNAL(clicked()), this, SLOT(ElevatorClose()));
	connect(ui.Floor1, SIGNAL(clicked()), this, SLOT(Floor1Clicked()));
	connect(ui.Floor2, SIGNAL(clicked()), this, SLOT(Floor2Clicked()));
	connect(ui.Floor3, SIGNAL(clicked()), this, SLOT(Floor3Clicked()));
	connect(ui.Floor4, SIGNAL(clicked()), this, SLOT(Floor4Clicked()));
}

ElevatorUserInterface::~ElevatorUserInterface()
{
}

void ElevatorUserInterface::ElevatorOpen()
{
	command->CommandType = OPEN;
	emit SendCommand(*command);
}

void ElevatorUserInterface::Floor1Clicked()
{
	command->CommandType = MOVE_TO_COMMAND;
	command->Destination = 1;
	emit SendCommand(*command);
}

void ElevatorUserInterface::Floor2Clicked()
{
	command->CommandType = MOVE_TO_COMMAND;
	command->Destination = 2;
	emit SendCommand(*command);
}

void ElevatorUserInterface::Floor3Clicked()
{
	command->CommandType = MOVE_TO_COMMAND;
	command->Destination = 3;
	emit SendCommand(*command);
}

void ElevatorUserInterface::Floor4Clicked()
{
	command->CommandType = MOVE_TO_COMMAND;
	command->Destination = 4;
	emit SendCommand(*command);
}

void ElevatorUserInterface::ElevatorClose()
{
	command->CommandType = CLOSE;
	emit SendCommand(*command);
}
