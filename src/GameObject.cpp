#include "GameObject.h"


GameObject::GameObject()
{
	curFrame = 1;
	curAnim = 1;
	animSet = 0;
}


GameObject::~GameObject()
{
}

int GameObject::getX(){return x;}
int GameObject::getY(){return y;}
int GameObject::getImageX(){return imageX;}
int GameObject::getImageY(){return imageY;}
int GameObject::getImageWidth(){return imageWidth;}
int GameObject::getImageHeight(){return imageHeight;}
int GameObject::getAnimSet(){return animSet;}
int GameObject::getMaxFrame(){return maxFrame;}
void GameObject::nextFrame(){if(maxFrame>curFrame){curFrame++;imageX+=imageWidth;}else{curFrame=1;imageX-=imageWidth*(maxFrame-1);}}
void GameObject::previousFrame(){if(0!=curFrame){curFrame--;imageX-=imageWidth;}else{curFrame=maxFrame;imageX+=imageWidth*(maxFrame-1);}}
void GameObject::nextAnimation(){if(maxAnim>curAnim){curAnim++;imageY+=imageHeight;}else{curAnim=1;imageY-=imageHeight*(maxAnim-1);}}
void GameObject::previousAnimation(){if(0!=curAnim){curAnim--;imageY-=imageHeight;}else{curAnim=maxAnim;imageY+=imageHeight*(maxAnim-1);}}