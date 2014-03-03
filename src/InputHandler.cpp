#include "InputHandler.h"

keyboardMap Data::inputMap = init();

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
		::updateKey(sf::Keyboard::Up);
		::updateKey(sf::Keyboard::Down);
		::updateKey(sf::Keyboard::Left);
		::updateKey(sf::Keyboard::Right);
}

std::pair<bool, bool> inputHandler::checkKey(sf::Keyboard::Key pressedKey){
		return Data::inputMap.find(pressedKey)->second;
}