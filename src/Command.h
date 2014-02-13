#ifndef COMMAND_H
#define COMMAND_H

#include "GameObject.h"

class Command
{
public:
	virtual ~Command(){};
	virtual void execute() = 0;

private:

};

class MoveCommand : public Command
{
public:
	MoveCommand(GameObject* obj, int x, int y) : obj(obj),x(x), y(y){};
	~MoveCommand(){};
	void execute();

private:
	GameObject * obj;
	int x, y;
};

#endif // !COMMAND_H
