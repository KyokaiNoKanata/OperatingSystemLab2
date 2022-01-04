#include "BuildingInterface.h"

BuildingInterface::BuildingInterface(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	c = new Command();
	QObject::connect(ui.Floor1UpButton, &QPushButton::clicked, this, &BuildingInterface::Floor1UpClicked);
	QObject::connect(ui.Floor2UpButton, &QPushButton::clicked, this, &BuildingInterface::Floor2UpClicked);
	QObject::connect(ui.Floor2DownButton, &QPushButton::clicked, this, &BuildingInterface::Floor2DownClicked);
	QObject::connect(ui.Floor3UpButton, &QPushButton::clicked, this, &BuildingInterface::Floor3UpClicked);
	QObject::connect(ui.Floor3DownButton, &QPushButton::clicked, this, &BuildingInterface::Floor3DownClicked);
	QObject::connect(ui.Floor4DownButton, &QPushButton::clicked, this, &BuildingInterface::Floor4DownClicked);
}

BuildingInterface::~BuildingInterface()
{
}

void BuildingInterface::Floor1UpClicked()
{
	c->Destination = 1;
	c->Destination = MOVING_UP;
	emit SendToThread1(*c);
}

void BuildingInterface::Floor2UpClicked()
{
	c->Destination = 2;
	c->Destination = MOVING_UP;
	emit SendToThread2(*c);
}

void BuildingInterface::Floor2DownClicked()
{
	c->Destination = 2;
	c->Destination = MOVING_DOWN;
	emit SendToThread2(*c);
}

void BuildingInterface::Floor3UpClicked()
{
	c->Destination = 3;
	c->Destination = MOVING_UP;
	emit SendToThread3(*c);
}

void BuildingInterface::Floor3DownClicked()
{
	c->Destination = 3;
	c->Destination = MOVING_DOWN;
	emit SendToThread3(*c);
}

void BuildingInterface::Floor4DownClicked()
{
	c->Destination = 4;
	c->Destination = MOVING_DOWN;
	emit SendToThread4(*c);
}
