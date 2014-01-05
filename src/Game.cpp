#include "Game.h"

Game::Game()
{
	mManager = new MediaManager();
	RenderWindow windowTemp(VideoMode(200, 200), "SFML works!");
	this->window = windowTemp;
}

void Game::init()
{
}

RenderWindow Game::getWindow()
{
	return Game::window;
}

MediaManager * Game::getManager()
{
	return Game::mManager;
}

void Game::loop()
{
	while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(playerObject->getSprite());
        window.display();
    }
}