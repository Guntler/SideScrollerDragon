#ifndef _INPUT_HANDLER_H
#define _INPUT_HANDLER_H

#include "SFML\Window\Keyboard.hpp"
#include <map>
#include <iostream> //for debug cout
#include <ctime>

typedef std::map<sf::Keyboard::Key, std::pair<bool, bool>> keyboardMap;
typedef std::pair<sf::Keyboard::Key, std::pair<bool, bool>> keyboardValue;

namespace{
	class Data{
	public:
		static keyboardMap inputMap;
		static keyboardMap init(){
			keyboardMap m;
			m.insert(keyboardValue(sf::Keyboard::Up, std::make_pair(true, true)));
			m.insert(keyboardValue(sf::Keyboard::Down, std::make_pair(true, true)));
			m.insert(keyboardValue(sf::Keyboard::Left, std::make_pair(true, true)));
			m.insert(keyboardValue(sf::Keyboard::Right, std::make_pair(true, true)));
			return m;
		}
	};
	void updateKey(sf::Keyboard::Key);
};

namespace inputHandler{
	void update();
	std::pair<bool, bool> checkKey(sf::Keyboard::Key);
};
#endif