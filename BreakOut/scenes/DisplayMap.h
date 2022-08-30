#pragma once
#include "Platform.h"
#include "Ball.h"
#include "BonusWall.h"

namespace game
{
	using DisplayElementMap = std::vector<std::string>;

	class DisplayMap
	{
	public:
		DisplayMap();
		void update();
		void increaseScore(const size_t count = 1);
		std::string build();
		void setObjectToMap(DisplayElementMap& map, const Point pos, const char symb);
		void updateDirection(MoveDirection direction);
		void checkBorderCollision();
		void checkPlatformCollision();
		void resetBall();
		bool checkGameOver();
		void checkWallCollision();
		std::vector<Point> getWallPoints();
		
	private:
		DisplayElementMap m_border;
		size_t m_maxWidht;
		size_t m_maxHeight;
		int m_score;
		size_t m_continue;
		game::Platform m_platform;
		game::Ball m_ball;
		std::vector<game::BonusWall> m_walls;
		bool pause;
	};
}

