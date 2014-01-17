#ifndef _CHARACTEROBJECT_H
#define _CHARACTEROBJECT_H

#include "MovingObject.h"

#include <math.h>

using namespace sf;

class CharacterObject : public MovingObject
{
public:
	CharacterObject();
protected:
	int getHP();
	bool isAffected(),hasAttack();
private:
	int hp;
	bool affected, attack;
};

#endif