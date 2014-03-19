#ifndef _BASES_MIXIN_H
#define _BASES_MIXIN_H

#include "GameObject.h"

enum TileTypes
{
	SOLID, PASSABLE
};

namespace{
	
	template<typename base>
	class HurtsPlayer : public base
	{
	public:

	private:

	};

	template<typename base>
	class Moving : public base
	{
	public:
		Moving() : base(){};
		Moving(int x, int y, int imageX, int imageY, int imageWidth, int imageHeight, int maxFrame, int maxAnim) : base(x, y, imageX, imageY, imageWidth, imageHeight, maxFrame, maxAnim){};
	private:

	};
}

namespace bases{
	
	class Tile : public GameObject
	{
	public:
		Tile() : GameObject(){ templateId = 0; };
		Tile(int x, int y, int imageX, int imageY, int imageWidth, int imageHeight, int maxFrame, int maxAnim, int id, float extraX, float extraY) : GameObject(x, y, imageX, imageY, imageWidth, imageHeight, maxFrame, maxAnim){ this->templateId = id; extraSpeed.x = extraX; extraSpeed.y = extraY; };
		~Tile(){};
		void setId(int id){ templateId = id; };
		int getId(){ return templateId; };
		sf::Vector2f getExtraSpeed() { return extraSpeed; }
	private:
		int templateId;
		sf::Vector2f extraSpeed;
	};

	class Living : public GameObject
	{
	public:
		Living() : GameObject(){};
		Living(int x, int y, int imageX, int imageY, int imageWidth, int imageHeight, int maxFrame, int maxAnim) : GameObject(x,y,imageX,imageY,imageWidth,imageHeight,maxFrame,maxAnim){};
		~Living(){};
		int getHp();
		void setHp(int hpToAdd);
	private:
		int hp;
	};

	class Player : public Moving<Living>
	{
	public:
		Player() : Moving<Living>(){};
		Player(int x, int y, int imageX, int imageY, int imageWidth, int imageHeight, int maxFrame, int maxAnim) : Moving<Living>(x, y, imageX, imageY, imageWidth, imageHeight, maxFrame, maxAnim){};
	private:

	};

	class Enemy : public HurtsPlayer<Moving<Living>>
	{
	public:

	private:

	};
}
#endif // !_BASES_MIXIN_H
