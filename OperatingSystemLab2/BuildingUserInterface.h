#pragma once

#include <QWidget>
#include "ui_BuildingUserInterface.h"

class BuildingUserInterface : public QWidget
{
	Q_OBJECT

public:
	BuildingUserInterface(QWidget *parent = Q_NULLPTR);
	~BuildingUserInterface();

private:
	Ui::BuildingUserInterface ui;
};
