#pragma once

#include <utility>

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
	
	/* Movement Related */
	float getAccX(), getAccY(), getDecX(), getJumpStartSpeed();
	sf::Vector2f getSpeed() { return speed; }
	sf::Vector2f getMaxSpeed() { return maxSpeed; }
	sf::Vector2f getActualMaxSpeed() { return actualMaxSpeed; }
	bool isJumping() { return jumping; }
	void toggleJumping() { if (jumping)jumping = false; else jumping = true; }

	/* Frame Related */
	void nextFrame(), previousFrame(), nextAnimation(), previousAnimation();
	CollisionTypes getIntersectingBorder(GameObject passiveObject);
	sf::RectangleShape getColBox();
	void setColBox(sf::RectangleShape box);
	void updatePosition();

protected:
	int x,y,imageX,imageY,imageWidth,imageHeight,curFrame,maxFrame,curAnim,maxAnim,animSet,colWidth,colHeight;
	sf::RectangleShape colBox;
	sf::Vector2f direction;
	
	float accX, decX;		//Acceleration/Deceleration to apply when the player moves/does not move
	sf::Vector2f speed;		//Movement in the next frame (Pixels per frame)
	sf::Vector2f maxSpeed;
	sf::Vector2f actualMaxSpeed;
	float jumpStartSpeed;
	float accY;		//Force to apply because of gravity
	std::pair<int, int> col_points[8];
	bool jumping;
	bool jumpKeyDown;
	bool contact[3] = { false, false, false };
};

