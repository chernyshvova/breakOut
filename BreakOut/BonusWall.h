#pragma once
#include "Types.h"

namespace game
{
	class BonusWall
	{
	public:
		BonusWall(const game::Point& pos, const size_t protection);
		void tryBreak();
		bool isBroken();
		std::vector<game::Point> getPoints() const;
		char getWallSkin()const;
		bool checkCollision(const game::Point& point)const;
		size_t getBonusCount()const;
	private:
		std::vector<game::Point> m_points;
		size_t m_protection;
		char m_skinType;
	};
}