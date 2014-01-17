#include "PlayerObject.h"

PlayerObject::PlayerObject(){}
PlayerObject::PlayerObject(int x, int y, int imageX, int imageY, int imageWidth, int imageHeight, int maxFrame, int maxAnim)
{
	this->x=x;
	this->y=y;
	this->imageX=imageX;
	this->imageY=imageY;
	this->imageWidth=imageWidth;
	this->imageHeight=imageHeight;
	this->maxFrame=maxFrame;
	this->maxAnim=maxAnim;
}