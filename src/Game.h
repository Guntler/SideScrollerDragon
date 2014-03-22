#ifndef _GAME_H
#define _GAME_H

#define WINDOW_WIDTH 280
#define WINDOW_HEIGHT 160

#include "SFML\Graphics\RenderWindow.hpp"
#include "MediaManager.h"
#include "Command.h"
#include "SFML\Window\Event.hpp"
#include "basesMixin.h"
#include "GameMap.h"
#include "InputHandler.h"
#include "Camera.h"
#include "Windows.h"

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using namespace std;

class Game
{
public:
	Game();
	~Game();
	void init();
	void loop();
	void checkMovement();
	void update();
	void checkCollisions();
	MediaManager * getManager();
	RenderWindow * getWindow();
	float linearMovement(float pixelsPerSecond, DWORD tickCount);
private:
	MediaManager * mManager;
	RenderWindow * window;
	GameObject * subjectA;
	bases::Tile * mapa[10][10];
	sf::View mainView;
	GameMap * map;
	int iterations = 20;
	float nextMoveX, nextMoveY;
	bool jumpKeyDown;
	bool moveRequest;
	float lastUpdateTime;
	int updateTick;
};

#endif
