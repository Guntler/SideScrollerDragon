#include "PlayerObject.h"

PlayerObject::PlayerObject(int x, int y, int imageX, int imageY, int imageWidth, int imageHeight)
{
	this->x=x;
	this->y=y;
	this->imageX=imageX;
	this->imageY=imageY;
	this->imageWidth=imageWidth;
	this->imageHeight=imageHeight;
	texID = Game::getManager()->loadTexture("hitboxes.png");
	sf::Sprite sprite;
	sprite.setTexture(*Game::getManager()->getTexture(texID));
}

void PlayerObject::draw(RenderWindow window)
{
	window.draw(sprite);
}