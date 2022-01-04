#pragma once

#include <QDialog>
#include <QPushButton>
#include "ui_ElevatorUserInterface.h"
#include "Command.h"

class ElevatorUserInterface :public QDialog
{
	Q_OBJECT

public:
	ElevatorUserInterface(QWidget* parent = Q_NULLPTR);
	~ElevatorUserInterface();

signals:
	void SendCommand(Command c);

public slots:
	void ElevatorClose();
	void ElevatorOpen();
	void Floor1Clicked();
	void Floor2Clicked();
	void Floor3Clicked();
	void Floor4Clicked();

private:
	Ui::ElevatorUserInterface ui;
	Command* command;
};
