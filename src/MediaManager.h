#ifndef _MEDIAMANAGER_H
#define _MEDIAMANAGER_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
using namespace sf;

/**
 *	The MediaManager stores loaded media, such as music, graphics and others.
 */
class MediaManager
{
public:
	MediaManager();
	int loadTexture(string name);
	Texture* getTexture(int id);
private:
	vector<Texture *> loadedTextures;
};

#endif