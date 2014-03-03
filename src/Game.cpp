#include "Game.h"

Game::Game()
{
	this->mManager = new MediaManager();
	this->window = new RenderWindow(VideoMode(160, 160), "SideScrollerDragon");
}

Game::~Game()
{
}

void Game::init(){
	subjectA = new bases::Player(0,0,0,0,16,16,1,1);
	subjectA->setPosition(0, 128);
	int id = this->mManager->loadTexture("hitboxes.png");
	subjectA->setTexture(*this->mManager->getTexture(id));
	map = new GameMap();
	string src = map->loadMap("testmap");
	//map = new GameMap();
	map->setId(this->mManager->loadTexture(src));
	
	/* MAP TESTING */
	/*id = this->mManager->loadTexture("tiles.png");
	int x;
	for (size_t i = 0; i < 10; i++){
		for (size_t j = 0; j < 10; j++){
			mapa[i][j] = new bases::Tile(0, 0, 0, 0, 16, 16, 2, 2);
			mapa[i][j]->setPosition(16 * (float)j, 16 * (float)i);
			mapa[i][j]->nextFrame();
			mapa[i][j]->setTexture(*this->mManager->getTexture(id));
			x = mapa[i][j]->getImageX() + mapa[i][j]->getImageWidth()*mapa[i][j]->getMaxFrame()*mapa[i][j]->getAnimSet();
			mapa[i][j]->setTextureRect(sf::IntRect(x, mapa[i][j]->getImageY(), mapa[i][j]->getImageWidth(), mapa[i][j]->getImageHeight()));
		}
	}

	for (size_t i = 0; i < 10; i++){
		mapa[9][i]->previousFrame();
		x = mapa[9][i]->getImageX() + mapa[9][i]->getImageWidth()*mapa[9][i]->getMaxFrame()*mapa[9][i]->getAnimSet();
		mapa[9][i]->setTextureRect(sf::IntRect(x, mapa[9][i]->getImageY(), mapa[9][i]->getImageWidth(), mapa[9][i]->getImageHeight()));
		mapa[9][i]->setType(TileTypes::SOLID);
	}*/
	/* END MAP TESTING */
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
		inputHandler::update();
		window->clear();
		Command * cmd;
		int moveX = 0, moveY = 0;
		if (inputHandler::checkKey(sf::Keyboard::Up).first)
			moveY--;
		if (inputHandler::checkKey(sf::Keyboard::Down).first)
			moveY++;
		if (inputHandler::checkKey(sf::Keyboard::Left).first)
			moveX--;
		if (inputHandler::checkKey(sf::Keyboard::Right).first)
			moveX++;
		
		cmd = new MoveCommand(subjectA, moveX, moveY);
		int x = subjectA->getImageX() + subjectA->getImageWidth()*subjectA->getMaxFrame()*subjectA->getAnimSet();
		subjectA->setTextureRect(sf::IntRect(x,subjectA->getImageY(),subjectA->getImageWidth(),subjectA->getImageHeight()));
		
		map->drawBackground(window,*this->mManager->getTexture(map->getId()));

		/* TEST MAP DRAW */
		/*for (size_t i = 0; i < 10; i++){
			for (size_t j = 0; j < 10; j++){
				window->draw(*mapa[i][j]);
			}
		}*/
		/* TEST MAP DRAW END */

		window->draw(*subjectA);
		subjectA->nextFrame();
		cmd->execute();
		delete cmd;
		window->display();
	}
}