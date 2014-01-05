#ifndef _GAME_H
#define _GAME_H

#include <SFML/Graphics.hpp>

#include "MediaManager.h"
#include "PlayerObject.h"

#include <math.h>

using namespace sf;

/**
 *	May describe the player, a tile or an enemy.
 */
class Game
{
public:
	Game();
	void init();
	void loop();
	static MediaManager * getManager();
	static RenderWindow getWindow();
private:
	MediaManager * Game::mManager;
	RenderWindow Game::window;
	PlayerObject * player;
};

#endif