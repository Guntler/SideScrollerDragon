#ifndef _PLAYEROBJECT_H
#define _PLAYEROBJECT_H

#include "CharacterObject.h"

#include <math.h>

using namespace sf;

class PlayerObject : protected CharacterObject
{
public:
	void draw(RenderWindow window);
protected:
private:
	
};

#endif