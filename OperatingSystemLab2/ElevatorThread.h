#pragma once

#include<QThread>

#include "ElevatorUserInterface.h"

class ElevatorThread :public QThread
{
	Q_OBJECT
public:
	ElevatorThread(QObject* parent = Q_NULLPTR);
private:
	void run();
};

