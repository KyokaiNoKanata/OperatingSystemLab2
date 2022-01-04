#include "Command.h"

Command::Command()
{
}

Command::Command(int commandtype, int destination, int direction, int sourcefloor)
{
	CommandType = commandtype;
	Destination = destination;
	Direction = direction;
}

bool Command::operator<(const Command& b)const
{
	return Destination < b.Destination;
}
