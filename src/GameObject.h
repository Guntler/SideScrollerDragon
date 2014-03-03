#pragma once
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\Sprite.hpp>

// Possible platform types
typedef enum {
	COL_UP = 0,
	COL_RIGHT = 1,
	COL_DOWN = 2,
	COL_LEFT = 3,
	COL_NONE = 4
} CollisionTypes;

class GameObject : public sf::Sprite
{
public:
	GameObject();
	GameObject(int x, int y, int imageX, int imageY, int imageWidth, int imageHeight, int maxFrame, int maxAnim);
	~GameObject();
	int getX(), getY(), getImageX(), getImageY(), getImageWidth(), getImageHeight(), getColWidth(), getColHeight(), getAnimSet(), getMaxFrame();
	void nextFrame(), previousFrame(), nextAnimation(), previousAnimation();
	CollisionTypes getIntersectingBorder(GameObject passiveObject);
	sf::RectangleShape getColBox();
	void setColBox(sf::RectangleShape box);
	void updatePosition();
protected:
	int x,y,imageX,imageY,imageWidth,imageHeight,curFrame,maxFrame,curAnim,maxAnim,animSet,colWidth,colHeight;
	sf::RectangleShape colBox;
	sf::Vector2f curSpeed;
	sf::Vector2f acceleration;
	sf::Vector2f direction;
	sf::Vector2f targetSpeed;
};

