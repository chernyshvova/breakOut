#include "stdafx.h"
#include "DisplayMap.h"
#include "ContentConstructorUtils.h"
#include "GameConfig.h"
#include "Platform.h"

namespace
{
	//Merge two elemets with same size. It function can be using for merging several walls textures or UI elements
	game::DisplayElementMap mergeElements(const game::DisplayElementMap& left, const game::DisplayElementMap right)
	{
		std::string emptyLine = std::string(left.begin()->size(), ' ');
		game::DisplayElementMap merged(left.size(), emptyLine);

		if (left.size() != right.size())
		{
			throw new std::exception("failed to merge two map elements with different sizes");
		}

		for (int i = 0; i < left.size(); i++)
		{
			for (int j = 0; j < left.cbegin()->size(); ++j)
			{
				if (left[i][j] != merged[i][j])
				{
					merged[i][j] = left[i][j];
				}

				if (right[i][j] != merged[i][j])
				{
					merged[i][j] = right[i][j];
				}
			}
		}

		return merged;
	}

	//Converting array of strings to strings display
	std::string convertMapToString(const game::DisplayElementMap& map)
	{
		std::string result = {};
		
		for (int i = 0; i < map.size(); ++i)
		{
			std::string newLine = map[i].c_str();
			result += newLine + '\n';
		}

		return result;
	}

	//random for bonus
	int getRandomPoint(const int min, const int max)
	{
		srand((unsigned int)time(NULL));
		auto res =  rand() % max + min;
		return res;
	}
}

game::DisplayMap::DisplayMap()
	: m_maxWidht(config::MAX_MAP_WIDTH)
	, m_maxHeight(config::MAX_MAP_HEIGHT)
	, m_score(0)
	, m_continue(game::config::DEFAULT_CONTINUE_COUNT)
{
	m_border = createBorderMap(m_maxWidht, m_maxHeight);
	int platformPosX = game::config::MAX_MAP_WIDTH / 2;
	int platformPosY = game::config::MAX_MAP_HEIGHT - 3;
	m_platform = game::Platform({ platformPosX,  platformPosY });
	resetBall();
	m_walls = createLevelWalls();
}

//makes move without drawing
void game::DisplayMap::update()
{	
	m_ball.updatePos();
}

void game::DisplayMap::increaseScore(const size_t count)
{
	m_score += count;
}

//prepare actual string for drawing.
std::string game::DisplayMap::build()
{
	std::string emptyLine = std::string(m_maxWidht, config::MAP_EMPTY_SYMB);
	DisplayElementMap mergedElements(m_maxHeight, emptyLine);
	
	//Empty map with borders(walls)
	mergedElements = mergeElements(mergedElements, m_border);
	
	//add string with score
	mergedElements[3] += config::SCORE_LABEL + std::to_string(m_score);
	mergedElements[4] += config::CONTINUE_LABEL + std::to_string(m_continue);
	//add objects

	for (auto& platformPoint : m_platform.getPoints())
	{
		setObjectToMap(mergedElements, platformPoint, game::config::PLATFORM_SYMB);
	}
	
	setObjectToMap(mergedElements, m_ball.getPos(), game::config::BALL_SYMB);

	for (auto& wall : m_walls)
	{
		for (auto& wallPoint : wall.getPoints())
		{
			setObjectToMap(mergedElements, wallPoint, wall.getWallSkin());
		}
	}

	return convertMapToString(mergedElements);
}

void game::DisplayMap::setObjectToMap(DisplayElementMap& map, const Point pos, const char symb)
{
	map[pos.y][pos.x] = symb;
}

//Update ball direction without drawing
void game::DisplayMap::updateDirection(MoveDirection direction)
{
	if (m_platform.getPoints().cbegin()->x >= game::config::MAX_MAP_WIDTH - game::config::PLATFORM_SIZE)
	{
		m_platform.moveLeft();
		return;
	}
	else if((m_platform.getPoints().cbegin()->x <= 0))
	{
		m_platform.moveRight();
		return;
	}

	if (direction == game::MoveDirection::Left)
	{
		m_platform.moveLeft();
	}
	else if (direction == game::MoveDirection::Right)
	{
		m_platform.moveRight();
	}
}

void game::DisplayMap::checkBorderCollision()
{
	auto nextPos = m_ball.getPos();
	if (m_border[nextPos.y][nextPos.x] == config::BORDER_SYMB_VERTICAL)
	{
		m_ball.changeHorizontalDirection();
	}
	if (m_border[nextPos.y][nextPos.x] == config::BORDER_SYMB_HORISONTAL)
	{

		m_ball.changeVerticalDirection();
	}
}

void game::DisplayMap::checkPlatformCollision()
{
	bool result = m_platform.checkCollision(m_ball.getPos());
	if (result)
	{
		m_ball.changeVerticalDirection();
	}
}

void game::DisplayMap::resetBall()
{
	m_ball = game::Ball({ config::MAX_MAP_WIDTH / 2, config::MAX_MAP_HEIGHT / 2 });
}

bool game::DisplayMap::checkGameOver()
{
	bool gameOverCollision = m_ball.getPos().y > m_platform.getPoints().begin()->y;
	if (gameOverCollision)
	{
		m_continue--;
		resetBall();
	}

	return m_continue == 0;
}

void game::DisplayMap::checkWallCollision()
{
	for (int i=0; i<m_walls.size(); ++i)
	{
		if (m_walls[i].checkCollision(m_ball.getPos()))
		{
			increaseScore(m_walls[i].getBonusCount());
			m_walls[i].tryBreak();
			m_ball.changeVerticalDirection();
			

			if (m_walls[i].isBroken())
			{
				m_walls.erase(m_walls.cbegin() + i);
			}
		}
	}
}

std::vector<game::Point> game::DisplayMap::getWallPoints()
{
	std::vector<Point> res = {};

	for (int i=0; i< m_border.size(); ++i)
	{
		for (int j =0; j< m_border[i].size(); ++j)
		{
			if (m_border[i][j] == config::BORDER_SYMB_VERTICAL || m_border[i][j] == config::BORDER_SYMB_HORISONTAL)
			{
				res.push_back({ j, i });
			}
		}
	}
	return res;

}
