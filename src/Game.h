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
	void update();
	MediaManager * getManager();
	RenderWindow * getWindow();
private:
	MediaManager * mManager;
	RenderWindow * window;
	GameObject * subjectA;
	bases::Tile * mapa[10][10];
	sf::View mainView;
	GameMap * map;
	int iterations = 3;
};

#endif
