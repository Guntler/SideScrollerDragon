#include "Command.h"

void MoveCommand::execute(){
	this->obj->move(x, y);
}