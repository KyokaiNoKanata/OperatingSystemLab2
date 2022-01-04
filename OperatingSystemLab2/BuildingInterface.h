#pragma once

#include <QDialog>
#include <QObject>
#include "Command.h"
#include "ui_BuildingInterface.h"

class BuildingInterface :public QDialog
{
	Q_OBJECT
public:
	BuildingInterface(QWidget* parent = Q_NULLPTR);
	~BuildingInterface();
	
public slots:
	void Floor1UpClicked();
	void Floor2UpClicked();
	void Floor2DownClicked();
	void Floor3UpClicked();
	void Floor3DownClicked();
	void Floor4DownClicked();

signals:
	void SendToThread1(Command c);
	void SendToThread2(Command c);
	void SendToThread3(Command c);
	void SendToThread4(Command c);

private:
	Command* c;
	Ui::BuildingInterface ui;
};
