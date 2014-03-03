#include "InputHandler.h"

keyboardMap Data::inputMap = init();
clock_t Data::lastHandle = 0;
bool Data::status = true;

void updateKey(sf::Keyboard::Key pressedKey){
	std::map<sf::Keyboard::Key, std::pair<bool, bool>>::iterator it;
	if (sf::Keyboard::isKeyPressed(pressedKey)){
		it = Data::inputMap.find(pressedKey);
		if (it->second.second){
			std::cout << "Key already pressed " << pressedKey << std::endl;
		}
		else{
			std::cout << "Key pressed " << pressedKey << std::endl;
			it->second.first = true;
			it->second.second = true;
		}
	}
	else {
		it = Data::inputMap.find(pressedKey);
		it->second.first = false;
		it->second.second = false;
	}
}

void inputHandler::update(){
	Data::status = false;
	clock_t now = clock() - Data::lastHandle;
	if ((now - Data::lastHandle) > Data::tickRange){
		Data::lastHandle = now;
		::updateKey(sf::Keyboard::Up);
		::updateKey(sf::Keyboard::Down);
		::updateKey(sf::Keyboard::Left);
		::updateKey(sf::Keyboard::Right);
		Data::status = true;
	}
}

std::pair<bool, bool> inputHandler::checkKey(sf::Keyboard::Key pressedKey){
	if (Data::status)
		return Data::inputMap.find(pressedKey)->second;
	else
		return std::make_pair<bool, bool>(false, false);
}