#pragma once

#define MOVE_TO_COMMAND 2
#define OPEN 1
#define CLOSE 0

class Command
{
public:
	Command();
	Command(int commandtype, int destination, int direction, int sourcefloor);
	int CommandType;
	int Destination;
	int Direction;
	bool operator<(const Command& b)const;
};
