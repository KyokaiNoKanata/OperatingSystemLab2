#pragma once

#include <QObject>
#include "Command.h"

class InterfaceInteract :
	public QObject
{
	Q_OBJECT
public:
	InterfaceInteract();
signals:
	void SendCommand(Command c);

public slots:
	void ReceiveCommand(Command c);
};

