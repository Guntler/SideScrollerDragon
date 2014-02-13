#ifndef _GAMEMAP_H
#define _GAMEMAP_H

#include "SFML\Graphics\RenderWindow.hpp"
#include <SFML\Graphics\Texture.hpp>

#include <iostream>
#include <string>
#include "basesMixin.h"

using sf::Texture;
using sf::RenderWindow;
using namespace std;

class GameMap
{
public:
	GameMap();
	GameMap(string filename);
	~GameMap();
	void drawBackground(RenderWindow * window, Texture tileset);
	void setId(int id);
	int getId();
private:
	int id;
	bases::Tile * layer1[10][10];
};

#endif
