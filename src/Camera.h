#pragma once

#include "SFML\Graphics\View.hpp"
#include "GameObject.h"

namespace Camera{
	void scrollCamera(GameObject * obj, sf::View * View, int windowWidth, int windowsHeight, int mapWidth, int mapHeight);
};
