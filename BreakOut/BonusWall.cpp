#include "stdafx.h"
#include "BonusWall.h"
#include "Types.h"
#include "GameConfig.h"

namespace
{
	char resolveWallLevelSkin(const size_t protection)
	{
		switch (protection)
		{
		case 1:
			return game::config::WALL_TYPE_1_SYMB;
		case 2:
			return game::config::WALL_TYPE_2_SYMB;
		default:
			return game::config::WALL_TYPE_3_SYMB;
		}
	}

	size_t resolveBonusCount(const size_t protection)
	{
		return protection;
	}
}
game::BonusWall::BonusWall(const game::Point& pos, const size_t protection)
	: m_protection(protection)
{
	m_points.push_back(pos);
	m_points.push_back({ pos.x + 1, pos.y });
	m_points.push_back({ pos.x,  pos.y +1 });
	m_points.push_back({ pos.x + 1, pos.y +1 });
	m_skinType = resolveWallLevelSkin(protection);
}

void game::BonusWall::tryBreak()
{
	m_protection--;
	m_skinType = resolveWallLevelSkin(m_protection);
}

bool game::BonusWall::isBroken()
{
	return !m_protection;
}

std::vector<game::Point> game::BonusWall::getPoints() const
{
	return m_points;
}

char game::BonusWall::getWallSkin() const
{
	return m_skinType;
}

bool game::BonusWall::checkCollision(const game::Point& collisionPos) const
{
	for (const auto& point : m_points)
	{		
		if (collisionPos.isEqual(point))
		{
			return true;
		}
	}
	return false;
}

size_t game::BonusWall::getBonusCount() const
{
	return resolveBonusCount(m_protection);
}
