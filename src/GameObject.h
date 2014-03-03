#pragma once
#include <SFML\Graphics\Sprite.hpp>

class GameObject : public sf::Sprite
{
public:
	GameObject();
	GameObject(int x, int y, int imageX, int imageY, int imageWidth, int imageHeight, int maxFrame, int maxAnim);
	~GameObject();
	int getX(), getY(), getImageX(), getImageY(), getImageWidth(), getImageHeight(), getAnimSet(), getMaxFrame();
	void nextFrame(), previousFrame(), nextAnimation(), previousAnimation();
	bool isIntersecting(GameObject passiveObject);
protected:
	int x,y,imageX,imageY,imageWidth,imageHeight,curFrame,maxFrame,curAnim,maxAnim,animSet;
};

