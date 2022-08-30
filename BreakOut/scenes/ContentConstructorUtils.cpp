#include "stdafx.h"
#include "ContentConstructorUtils.h"
#include "GameConfig.h"

/*
Create border map.There is implementing wall form crating.

another example of walls

return{{###########},
	   {###    ####},
	   {###    ####},
	   {###########}},
*/

std::vector<std::string> game::createBorderMap(const size_t maxWith, const size_t maxHeight)
{
	std::string emptyLine = std::string(maxWith, config::MAP_EMPTY_SYMB);
	std::vector<std::string> resultMap(maxHeight, emptyLine);

	for (int i = 0; i < maxHeight; ++i)
	{
		for (int j = 0; j < maxWith; ++j)
		{
			if (i == 0 || i == maxHeight - 1)
			{
				resultMap[i][j] = (config::BORDER_SYMB_HORISONTAL);
			}
			else if (j == 0 || j == maxWith - 1)
			{
				resultMap[i][j] = (config::BORDER_SYMB_VERTICAL);
			}
			else
			{
				resultMap[i][j] = (config::MAP_EMPTY_SYMB);
			}
		}
	}

	return resultMap;
}

std::vector<game::BonusWall> game::createLevelWalls()
{
	game::Point wallsStartPoint = { game::config::MAX_MAP_WIDTH / 2, game::config::MAX_MAP_HEIGHT - 10 };
	std::vector<game::BonusWall> walls;
	walls.push_back(BonusWall({ wallsStartPoint.x, wallsStartPoint.y }, 2));
	walls.push_back(BonusWall({ wallsStartPoint.x + 3, wallsStartPoint.y }, 1));
	walls.push_back(BonusWall({ wallsStartPoint.x + 6, wallsStartPoint.y }, 2));
	walls.push_back(BonusWall({ wallsStartPoint.x + 6, wallsStartPoint.y }, 3));
	walls.push_back(BonusWall({ wallsStartPoint.x + 9, wallsStartPoint.y }, 3));
	walls.push_back(BonusWall({ wallsStartPoint.x + 12, wallsStartPoint.y }, 3));
	walls.push_back(BonusWall({ wallsStartPoint.x + -3, wallsStartPoint.y }, 1));
	walls.push_back(BonusWall({ wallsStartPoint.x + -6, wallsStartPoint.y }, 2));
	walls.push_back(BonusWall({ wallsStartPoint.x + -9, wallsStartPoint.y }, 3));
	walls.push_back(BonusWall({ wallsStartPoint.x + -12, wallsStartPoint.y }, 3));
	return walls;
}
