#include "stdafx.h"
#include "Platform.h"
#include "GameConfig.h"

game::Platform::Platform()
{
}

game::Platform::Platform(const game::Point defaultPos)
{
	for (int i = 0, defPosX = defaultPos.x; i < game::config::PLATFORM_SIZE; ++i, defPosX ++)
	{
		m_points.push_back(game::Point{ defPosX, defaultPos.y});
	}
}

std::vector<game::Point> game::Platform::getPoints() const
{
	return m_points;
}

void game::Platform::moveLeft()
{
	for (auto& point : m_points)
	{
		point.x--;
	}
}

void game::Platform::moveRight()
{
	for (auto& point : m_points)
	{
		point.x++;
	}
}

bool game::Platform::checkCollision(const game::Point pos)
{
	for (auto& point : m_points)
	{
		if (point.isEqual(pos))
		{
			return true;
		}
	}
	return false;
}
