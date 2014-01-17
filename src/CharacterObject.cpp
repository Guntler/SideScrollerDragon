#include "CharacterObject.h"

CharacterObject::CharacterObject(){}
int CharacterObject::getHP(){return this->hp;}
bool CharacterObject::isAffected(){return this->affected;}
bool CharacterObject::hasAttack(){return this->attack;}