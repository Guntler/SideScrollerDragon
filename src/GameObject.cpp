#include "GameObject.h"


GameObject::GameObject()
{
	curFrame = 1;
	curAnim = 1;
	animSet = 0;
}


GameObject::GameObject(int x, int y, int imageX, int imageY, int imageWidth, int imageHeight, int maxFrame, int maxAnim)
{
	// FPS
	float mScale = 60.f;

	this->x = x;
	this->y = y;
	this->imageX = imageX;
	this->imageY = imageY;
	this->imageWidth = imageWidth;
	this->imageHeight = imageHeight;
	this->maxFrame = maxFrame;
	this->maxAnim = maxAnim;
	this->curFrame = 1;
	this->curAnim = 1;
	this->animSet = 0;
	this->colWidth = 16;
	this->colHeight = 16;
	colBox = sf::RectangleShape(sf::Vector2f((float)colWidth, (float)colHeight));
}

GameObject::~GameObject()
{
}

int GameObject::getX(){return x;}
int GameObject::getY(){return y;}
int GameObject::getImageX(){return imageX;}
int GameObject::getImageY(){return imageY;}
int GameObject::getImageWidth(){return imageWidth;}
int GameObject::getImageHeight(){return imageHeight;}
int GameObject::getColWidth(){ return colWidth; }
int GameObject::getColHeight(){ return colHeight; }
int GameObject::getAnimSet(){return animSet;}
int GameObject::getMaxFrame(){return maxFrame;}
float GameObject::getAccX(){ return accX; }
float GameObject::getDecX(){ return decX; }
float GameObject::getAccY(){ return accY; }
float GameObject::getJumpStartSpeed(){ return jumpStartSpeed; }
void GameObject::nextFrame(){if(maxFrame>curFrame){curFrame++;imageX+=imageWidth;}else{curFrame=1;imageX-=imageWidth*(maxFrame-1);}}
void GameObject::previousFrame(){if(0!=curFrame){curFrame--;imageX-=imageWidth;}else{curFrame=maxFrame;imageX+=imageWidth*(maxFrame-1);}}
void GameObject::nextAnimation(){if(maxAnim>curAnim){curAnim++;imageY+=imageHeight;}else{curAnim=1;imageY-=imageHeight*(maxAnim-1);}}
void GameObject::previousAnimation(){if(0!=curAnim){curAnim--;imageY-=imageHeight;}else{curAnim=maxAnim;imageY+=imageHeight*(maxAnim-1);}}
void GameObject::setColBox(sf::RectangleShape box){ colBox = box; }
sf::RectangleShape GameObject::getColBox(){ return colBox; }
CollisionTypes GameObject::getIntersectingBorder(GameObject passiveObject)
{
	int activeLowerBound = passiveObject.getY() + passiveObject.getColHeight();
	int activeUpperBound = passiveObject.getY();
	int activeBackwardBound = passiveObject.getX();
	int activeForwardBound = passiveObject.getX() + passiveObject.getColWidth();

	int passiveLowerBound = passiveObject.getY() + passiveObject.getColHeight();
	int passiveUpperBound = passiveObject.getY();
	int passiveBackwardBound = passiveObject.getX();
	int passiveForwardBound = passiveObject.getX() + passiveObject.getColWidth();

	if ((activeLowerBound <= passiveUpperBound && activeLowerBound >= passiveLowerBound)
		|| (activeUpperBound <= passiveUpperBound && activeUpperBound >= passiveLowerBound))
	{
		if (direction.x > 0)
		{
			if ((activeForwardBound >= passiveBackwardBound) && (activeForwardBound <= passiveForwardBound))
				return COL_RIGHT;
		}
		else if (direction.x < 0)
		{
			if ((activeBackwardBound >= passiveBackwardBound) && (activeBackwardBound <= passiveForwardBound))
				return COL_LEFT;
		}
	}

	if ((activeForwardBound >= passiveBackwardBound) && (activeForwardBound <= passiveForwardBound)
		|| (activeBackwardBound >= passiveBackwardBound) && (activeBackwardBound <= passiveForwardBound))
	{
		if (direction.y > 0)
		{
			if ((activeLowerBound <= passiveUpperBound && activeLowerBound >= passiveLowerBound))
				return COL_UP;
		}
		else if (direction.y < 0)
		{
			if ((activeUpperBound <= passiveUpperBound && activeUpperBound >= passiveLowerBound))
				return COL_DOWN;
		}
	}

	/*if ((activeLowerBound <= passiveUpperBound && activeLowerBound >= passiveLowerBound)
		|| (activeUpperBound <= passiveUpperBound && activeUpperBound >= passiveLowerBound))
	{
		if ((activeForwardBound >= passiveBackwardBound) && (activeForwardBound <= passiveForwardBound))
			return COL_RIGHT;
		else if ((activeBackwardBound >= passiveBackwardBound) && (activeBackwardBound <= passiveForwardBound))
			return COL_LEFT;
	}*/

	return COL_NONE;
}
void GameObject::updatePosition()
{

}