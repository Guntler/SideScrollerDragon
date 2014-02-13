#ifndef _GAMEMAP_H
#define _GAMEMAP_H

#include "SFML\Graphics\RenderWindow.hpp"
#include <SFML\Graphics\Texture.hpp>

#include <iostream>
#include <string>
#include "basesMixin.h"
#include "../include/tinyxml.h"
#include "../include/tinystr.h"

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
	void loadMap();
private:
	int id;
	int width, height;
	bases::Tile * layer1[10][10];
};

#endif
