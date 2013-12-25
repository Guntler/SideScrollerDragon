#ifndef _MOVINGOBJECT_H
#define _MOVINGOBJECT_H

#include "GameObject.h"

#include <math.h>

using namespace sf;

class MovingObject : protected GameObject
{
public:
	virtual void draw(RenderWindow window) = 0;
protected:
	int * getCollisionPts();
	bool hasGravity();
private:
	int collisionPoints[6];
	bool gravity;
};

#endif