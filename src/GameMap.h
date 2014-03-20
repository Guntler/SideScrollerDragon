#ifndef _GAMEMAP_H
#define _GAMEMAP_H

#include "SFML\Graphics\RenderWindow.hpp"
#include <SFML\Graphics\Texture.hpp>

#include <iostream>
#include <string>
#include <unordered_map>
#include "basesMixin.h"
#include "../include/tinyxml.h"
#include "../include/tinystr.h"

using sf::Texture;
using sf::RenderWindow;
using namespace std;

class TileTemplate
{
public:
	void addProperty(string attribute, int value) { templateMap.insert({ attribute, value }); }
	int getValue(string attribute) {
		return this->templateMap.find(attribute)->second;
	};
private:
	unordered_map<string, int> templateMap;
};

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
	sf::Vector2i getSize();
	vector<vector<bases::Tile *>> getCollisionLayer();
	bases::Tile * getTileNumber(int no);
	int getPassabilityAt(int id);
private:
	int id;
	int width, height;
	bases::Tile * ** background;
	vector< vector<bases::Tile *> > layer1;
	unordered_map<int, TileTemplate *> templateTiles;
};

#endif