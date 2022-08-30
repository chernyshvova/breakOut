#pragma once
#include "BonusWall.h"

//utils for level content initalizing
namespace game
{
	std::vector<std::string> createBorderMap(const size_t maxWith, const size_t maxHeight);
	std::vector<game::BonusWall> createLevelWalls();
}
