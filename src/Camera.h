#pragma once

#include "SFML\Graphics\View.hpp"
#include "GameObject.h"

namespace Camera{
	void centerCamera(GameObject * obj, sf::View * view, int windowWidth, int windowsHeight, int mapWidth, int mapHeight);
};
