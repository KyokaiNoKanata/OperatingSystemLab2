#pragma once

#define MOVE_TO_COMMAND 2
#define OPEN 1
#define CLOSE 0
#define STILL 0
#define MOVING_UP 1
#define MOVING_DOWN 2
#define DOOR_CLOSE 0
#define DOOR_OPEN 1
#define UP 1
#define DOWN 0
#define STOP 3

class Command
{
public:
	Command();
	Command(int commandtype, int destination, int direction);
	int CommandType;
	int Destination;
	int Direction;
	bool operator<(const Command& b)const;
};
