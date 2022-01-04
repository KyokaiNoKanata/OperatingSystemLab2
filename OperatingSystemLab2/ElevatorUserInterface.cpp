#include "ElevatorUserInterface.h"

ElevatorUserInterface::ElevatorUserInterface(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.Open, SIGNAL(clicked()), this, SLOT(ElevatorOpen()));
	connect(ui.Close, SIGNAL(clicked()), this, SLOT(ElevatorClose()));
}

ElevatorUserInterface::~ElevatorUserInterface()
{
}

void ElevatorUserInterface::ElevatorOpen()
{
	emit SendCommand("Open");
}

void ElevatorUserInterface::ElevatorClose()
{
	emit SendCommand("Close");
}
