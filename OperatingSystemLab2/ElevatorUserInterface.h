#pragma once

#include <QWidget>
#include "ui_ElevatorUserInterface.h"

class ElevatorUserInterface : public QWidget
{
	Q_OBJECT

public:
	ElevatorUserInterface(QWidget* parent = Q_NULLPTR);
	~ElevatorUserInterface();

private:
	Ui::ElevatorUserInterface ui;
};
