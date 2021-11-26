#pragma once

#pragma once

#include <QWidget>

#include "ui_ElevatorUserInterface.h"
#include "ElevatorThread.h"
#include "ElevatorUserInterface.h"

class ElevatorUserInterface :public QWidget
{
	Q_OBJECT
public:
	ElevatorUserInterface(QWidget* parent = Q_NULLPTR);
	~ElevatorUserInterface();
private:
	Ui::ElevatorUserInterface ui;
};
