#include "Game.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	Game game = Game();
	game.init();
	game.loop();

    return 0;
}