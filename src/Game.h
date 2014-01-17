#ifndef _GAME_H
#define _GAME_H

#include "SFML\Graphics\RenderWindow.hpp"
#include "SFML\Graphics\RenderWindow.hpp"
#include "MediaManager.h"

#include "SFML\Window\Event.hpp"
#include "PlayerObject.h"

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
	MediaManager * getManager();
	RenderWindow * getWindow();
private:
	MediaManager * mManager;
	RenderWindow * window;
	PlayerObject * subjectA;
};

#endif
