#pragma once

#include <iostream>
#include <vector>
#include <SFML\Graphics\Texture.hpp>

using std::vector;
using std::string;
using sf::Texture;
using std::cout;
using std::cin;
using std::endl;

class MediaManager
{
public:
	MediaManager();
	~MediaManager();
	int loadTexture(string);
	Texture * getTexture(int id);
protected:
	vector<Texture*> textures; // temporary defenition
};

