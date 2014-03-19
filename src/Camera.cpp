#include "Camera.h"

void Camera::centerCamera(GameObject * obj, sf::View * view, int windowWidth, int windowHeight, int mapWidth, int mapHeight){
	if (obj->getPosition().x > view->getCenter().x && view->getCenter().x < (mapWidth - windowWidth / 2)){
		view->setCenter(view->getCenter().x + (obj->getPosition().x - view->getCenter().x), view->getCenter().y);
	}
	else if (obj->getPosition().x < view->getCenter().x  && view->getCenter().x > (windowWidth / 2)){
		view->setCenter(view->getCenter().x - (view->getCenter().x - obj->getPosition().x), view->getCenter().y);
	}
	if (obj->getPosition().y > view->getCenter().y && view->getCenter().y < (mapHeight - windowHeight / 2)){
		view->setCenter(view->getCenter().x, view->getCenter().y + (obj->getPosition().y - view->getCenter().y));
	}
	else if (obj->getPosition().y < view->getCenter().y && obj->getPosition().y > (windowHeight / 2)){
		view->setCenter(view->getCenter().x, view->getCenter().y - (view->getCenter().y - obj->getPosition().y));
	}

	if (view->getCenter().y > mapHeight - windowHeight / 2){
		view->setCenter(view->getCenter().x, mapHeight - windowHeight / 2);
	}
	if (view->getCenter().x > mapWidth - windowWidth / 2){
		view->setCenter(mapWidth - windowWidth / 2,view->getCenter().y);
	}
}