#include "Command.h"

Command::Command()
{
	CommandType = MOVE_TO_COMMAND;
	Destination = 1;
	Direction = STILL;
}

Command::Command(int commandtype, int destination, int direction)
{
	CommandType = commandtype;
	Destination = destination;
	Direction = direction;
}

bool Command::operator<(const Command& b)const
{
	return Destination < b.Destination;
}
