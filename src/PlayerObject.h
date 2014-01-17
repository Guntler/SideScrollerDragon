#ifndef _PLAYEROBJECT_H
#define _PLAYEROBJECT_H

#include "CharacterObject.h"

#include <math.h>

using namespace sf;

class PlayerObject : public CharacterObject
{
public:
	PlayerObject();
	PlayerObject(int x, int y, int imageX, int imageY, int imageWidth, int imageHeight, int maxFrame, int maxAnim);
protected:
private:
	
};

#endif