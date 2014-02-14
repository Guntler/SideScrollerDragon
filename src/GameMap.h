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
	string loadMap(string filename);
	void loadDefault();
private:
	int id;
	int width, height;
	bases::Tile * ** background;
	vector< vector<bases::Tile *> > layer1;
};

#endif
