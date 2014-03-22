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
	void setSpeed(int x, int y) { speed.x = (float)x; speed.y = (float)y; }
	bool isJumping() { return jumping; }
	void toggleJumping() { if (jumping)jumping = false; else jumping = true; }
	void setJumping(bool state) { jumping = state; }
	bool hasContactX() { return contact[0]; }
	bool hasContactYTop() { return contact[1]; }
	bool hasContactYBottom() { return contact[2]; }
	void toggleContactX() { if (contact[0])contact[0] = false; else contact[0] = true; }
	void toggleContactYTop() { if (contact[1])contact[1] = false; else contact[1] = true; }
	void toggleContactYBottom() { if (contact[2])contact[2] = false; else contact[2] = true; }
	void setContactX(bool state) { contact[0] = state; }
	void setContactYTop(bool state) { contact[1] = state; }
	void setContactYBottom(bool state) { contact[2] = state; }
	void addSpeed(float x, float y) { speed.x += x; speed.y += y; }
	/* Frame Related */
	void nextFrame(), previousFrame(), nextAnimation(), previousAnimation();
	CollisionTypes getIntersectingBorder(GameObject passiveObject);
	sf::RectangleShape getColBox();
	void setColBox(sf::RectangleShape box);
	void updatePosition();

	std::pair<int, int> col_points[8];
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
	bool jumping;
	bool jumpKeyDown;
	bool contact[3];
};

