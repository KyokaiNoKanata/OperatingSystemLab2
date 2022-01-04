#pragma once

#include <QDialog>
#include <QPushButton>
#include "ui_ElevatorUserInterface.h"

class ElevatorUserInterface :public QDialog
{
	Q_OBJECT

public:
	ElevatorUserInterface(QWidget* parent = Q_NULLPTR);
	~ElevatorUserInterface();

signals:
	void SendCommand(QString qs);

private slots:
	void ElevatorClose();
	void ElevatorOpen();

private:
	Ui::ElevatorUserInterface ui;
};
