#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <SFML/Graphics.hpp>

#include <math.h>

using namespace sf;

/**
 *	May describe the player, a tile or an enemy.
 */
class GameObject
{
public:
	virtual void draw(RenderWindow window) = 0;
protected:
	int getX();			int getY();
	int getImageX();	int getImageY();
	int getWidth();		int getHeight();
	void addX(int sum);	void addY(int sum);
private:
	int x,y,imageX,imageY,width,height;
};

#endif