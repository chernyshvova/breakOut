#pragma once
#include <Types.h>
namespace game
{
	class Platform
	{
	public:
		Platform();
		Platform(const game::Point defaultPos);
		std::vector<game::Point> getPoints()const;
		void moveLeft();
		void moveRight();
		bool checkCollision(const game::Point pos);
	private:
		std::vector<game::Point> m_points;
	};
}


