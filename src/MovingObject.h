#ifndef _MOVINGOBJECT_H
#define _MOVINGOBJECT_H

#include "GameObject.h"

#include <math.h>

using namespace sf;

class MovingObject : public GameObject
{
public:
protected:
	int * getCollisionPts();
	bool hasGravity();
private:
	int collisionPoints[6];
	bool gravity;
};

#endif