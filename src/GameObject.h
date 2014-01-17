#pragma once
#include <SFML\Graphics\Sprite.hpp>

class GameObject : public sf::Sprite
{
public:
	GameObject();
	~GameObject();
	int getX(), getY(), getImageX(), getImageY(), getImageWidth(), getImageHeight(), getAnimSet(), getMaxFrame();
	void nextFrame(), previousFrame(), nextAnimation(), previousAnimation();
protected:
	int x,y,imageX,imageY,imageWidth,imageHeight,curFrame,maxFrame,curAnim,maxAnim,animSet;
};

