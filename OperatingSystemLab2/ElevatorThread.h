#pragma once

#include<QThread>
#include<QString>

#include "ElevatorUserInterface.h"

class ElevatorThread :
	public QThread
{
public:
	void run();
};

