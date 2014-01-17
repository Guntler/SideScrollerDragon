#include "MediaManager.h"


MediaManager::MediaManager()
{
}


MediaManager::~MediaManager()
{
}

int MediaManager::loadTexture(string name){
	string path = "../img/";
	path.append(name);
	Texture * tex = new Texture();
	if (!tex->loadFromFile(name))
	{
		cout << "Error loading texture " << name << endl;
		exit(-1);
	}
	textures.push_back(tex);
	return textures.size() - 1;
}

Texture * MediaManager::getTexture(int id){
	if (0 <= id && id < textures.size())
		return textures[id];
	else
	{
		cout << "Attempted to access unexisting position of the graphics vector." << endl;
		exit(-1);
	}
}