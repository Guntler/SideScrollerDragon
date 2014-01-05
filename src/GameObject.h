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
	GameObject();
	virtual void draw(RenderWindow window) = 0;
protected:
	int getX();			int getY();
	int getImageX();	int getImageY();
	int getWidth();		int getHeight();
	int getImageWidth();	int getImageHeight();
	void addX(int sum);	void addY(int sum);

	int x,y,width,height;	//Drawing coordinates
	int imageX,imageY,imageWidth,imageHeight;	//Coordinates of the image itself in its respective spritesheet
	int colX,colY,colW,colH;	//Coordinates of the hitbox
	int animIndex;	//Index of the set of frames to use
	int frameIndex;	//Index of the frame to use
	int maxAnims;	//Max value of animIndex-1
	int * maxFrames;//Max value of frameIndex-1
	int texID;		//ID of the texture in MediaManager's texture vector
};

#endif