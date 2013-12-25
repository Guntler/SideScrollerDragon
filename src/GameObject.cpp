#include "GameObject.h"

int GameObject::getX(){return this->x;}
int GameObject::getY(){return this->y;}
int GameObject::getImageX(){return this->imageX;}
int GameObject::getImageY(){return this->imageY;}
int GameObject::getWidth(){return this->width;}
int GameObject::getHeight(){return this->height;}
void GameObject::addX(int sum){this->x+=sum;}
void GameObject::addY(int sum){this->y+=sum;}