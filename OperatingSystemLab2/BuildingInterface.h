#pragma once

#include <QDialog>
#include "ui_BuildingInterface.h"

class BuildingInterface : public QDialog
{
	Q_OBJECT

public:
	BuildingInterface(QWidget *parent = Q_NULLPTR);
	~BuildingInterface();

private:
	Ui::BuildingInterface ui;
};
