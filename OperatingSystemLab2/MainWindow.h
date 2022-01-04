#pragma once

#include <QtWidgets/QMainWindow>
#include <QObject>
#include <vector>

#include "ui_MainWindow.h"
#include "Elevator.h"
#include "ElevatorUserInterface.h"

class MainWindow :public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = Q_NULLPTR);

private slots:
	void ReceiveMessage(QString qs);

private:
	Ui::MainWindowClass ui;
	ElevatorUserInterface* eui;
	std::vector<Elevator>ElevatorVector;
};
