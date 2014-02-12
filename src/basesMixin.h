#ifndef _BASES_MIXIN_H
#define _BASES_MIXIN_H

#include "GameObject.h"

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

	private:

	};
}

namespace bases{
	
	class Living : public GameObject
	{
	public:
		Living();
		~Living();
		int getHp();
		void setHp(int hpToAdd);
	private:
		int hp;
	};

	class Player : public Moving<Living>
	{
	public:

	private:

	};

	class Enemy : public HurtsPlayer<Moving<Living>>
	{
	public:

	private:

	};
}
#endif // !_BASES_MIXIN_H
