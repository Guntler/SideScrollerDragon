#ifndef _CHARACTEROBJECT_H
#define _CHARACTEROBJECT_H

#include "MovingObject.h"

#include <math.h>

using namespace sf;

class CharacterObject : protected MovingObject
{
public:
	virtual void draw(RenderWindow window) = 0;
protected:
	int getHP();
	bool isAffected(),hasAttack();
private:
	int hp;
	bool affected, attack;
};

#endif