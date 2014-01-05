#include "MediaManager.h"

MediaManager::MediaManager(){}

/**
 *	Loads a texture with the supplied name, and returns the position of the loaded graphic in the graphics vector upon success.
 *	Should maybe store the name as well in case the system tries to refresh all graphics.
 *	Instead of generating an error and exiting, the system should maybe load a predefined texture (sort of a 'missing texture' graphic')
 *	If all else fails, create an empty texture from scratch using SFML's default capabilities. The system should then attempt, every once in a while,
 *	to reload the picture through the same means.
 *	If even THAT fails, then generate an error and exit.
 */
int MediaManager::loadTexture(string name)
{
	string path = "../img/";
	path.append(name);
	Texture tex;
	if (!tex.loadFromFile(name))
	{
		cerr << strerror(errno) << "Error loading texture " << path << endl;
		exit(-1);
	}
	loadedTextures.push_back(tex);
	return loadedTextures.size()-1;
}

Texture MediaManager::getTexture(int id)
{
	if(0<=id)
		return loadedTextures[id];
	else
	{
		cerr << "Attempted to access unexisting position of the graphics vector." << endl;
		exit(-1);
	}

}