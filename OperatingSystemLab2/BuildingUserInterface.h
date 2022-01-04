#pragma once

#include <QWidget>
#include "ui_BuildingUserInterface.h"
#include "Command.h"

class BuildingUserInterface : public QWidget
{
	Q_OBJECT

public:
	BuildingUserInterface(QWidget *parent = Q_NULLPTR);
	~BuildingUserInterface();

private:
	Ui::BuildingUserInterface ui;
};
