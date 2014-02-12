#include "Game.h"

Game::Game()
{
	this->mManager = new MediaManager();
	this->window = new RenderWindow(VideoMode(340, 240), "SideScrollerDragon");
}

Game::~Game()
{
}

void Game::init(){
	subjectA = new bases::Player(0,0,0,0,16,32,4,4);
	subjectA->setPosition(30, 35);
	int id = this->mManager->loadTexture("hitboxes.png");
	subjectA->setTexture(*this->mManager->getTexture(id));
}

void Game::loop(){
	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}

		window->clear();
		int x = subjectA->getImageX() + subjectA->getImageWidth()*subjectA->getMaxFrame()*subjectA->getAnimSet();
		subjectA->setTextureRect(sf::IntRect(x,subjectA->getImageY(),subjectA->getImageWidth(),subjectA->getImageHeight()));
		window->draw(*subjectA);
		subjectA->nextFrame();
		window->display();
	}
}