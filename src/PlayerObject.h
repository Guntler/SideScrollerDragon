#ifndef _PLAYEROBJECT_H
#define _PLAYEROBJECT_H

#include "CharacterObject.h"
#include "Game.h"

#include <math.h>

using namespace sf;

class PlayerObject : protected CharacterObject
{
public:
	PlayerObject(int x, int y, int imageX, int imageY, int imageWidth, int imageHeight);
	Sprite getSprite();
	void draw(RenderWindow window);
protected:
private:
	Sprite sprite;
	
};

#endif