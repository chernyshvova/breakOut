#include "stdafx.h"
#include "Ball.h"

game::Ball::Ball()
{
}

game::Ball::Ball(const game::Point startPoint)
	: m_currentPoint(startPoint)
	, m_currentDirection(game::MoveDirection::Down)
{
}

const game::Point game::Ball::getPos()
{
	return m_currentPoint;
}

void game::Ball::updatePos()
{
	switch (m_currentDirection)
	{
	case game::MoveDirection::Top:
		m_currentPoint.y--;
		break;
	case game::MoveDirection::Down:
		m_currentPoint.y++;
		break;
	case game::MoveDirection::Right:
		m_currentPoint.x++;
		break;
	case game::MoveDirection::Left:
		m_currentPoint.x--;
		break;
	case game::MoveDirection::TopRight:
		m_currentPoint.y--;
		m_currentPoint.x++;
		break;
	case game::MoveDirection::TopLeft:
		m_currentPoint.y--;
		m_currentPoint.x--;
		break;
	case game::MoveDirection::DownRight:
		m_currentPoint.y++;
		m_currentPoint.x++;
		break;
	case game::MoveDirection::DownLeft:
		m_currentPoint.y++;
		m_currentPoint.x--;
		break;
	default:
		break;
	}
}

void game::Ball::changeHorizontalDirection()
{
	switch (m_currentDirection)
	{

		case game::MoveDirection::DownLeft:
		case game::MoveDirection::Left:
		case game::MoveDirection::TopLeft:
			m_currentDirection = getRightRandomDirection();
			break;
		case game::MoveDirection::DownRight:
		case game::MoveDirection::Right:
		case game::MoveDirection::TopRight:
			m_currentDirection = getLeftRandomDirection();
		default:
			throw new std::exception("failed to parse ball moving");
	}

}

void game::Ball::changeVerticalDirection()
{
	switch (m_currentDirection)
	{

	case game::MoveDirection::DownLeft:
	case game::MoveDirection::Down:
	case game::MoveDirection::DownRight:
		m_currentDirection = getTopRandomDirection();
		break;
	case game::MoveDirection::TopRight:
	case game::MoveDirection::Top:
	case game::MoveDirection::TopLeft:
		m_currentDirection = getDownRandomDirection();
	default:
		throw new std::exception("failed to parse ball moving");
	}
}

game::MoveDirection game::Ball::getTopRandomDirection()
{
	srand(time(NULL));
	auto randomDirection = rand() % 3 + 1;

	switch (randomDirection)
	{
		case 1:
			return game::MoveDirection::TopLeft;
		case 2:
			return game::MoveDirection::Top;
		case 3:
			return game::MoveDirection::TopRight;
		default:
			throw new std::exception("failed to parse ball moving");
	}

}

game::MoveDirection game::Ball::getDownRandomDirection()
{
	srand(time(NULL));
	auto randomDirection = rand() % 3 + 1;

	switch (randomDirection)
	{
	case 1:
		return game::MoveDirection::Down;
	case 2:
		return game::MoveDirection::DownLeft;
	case 3:
		return game::MoveDirection::DownRight;
	default:
		throw new std::exception("failed to parse ball moving");
	}
}

game::MoveDirection game::Ball::getLeftRandomDirection()
{
	srand(time(NULL));
	auto randomDirection = rand() % 3 + 1;

	switch (randomDirection)
	{
	case 1:
		return game::MoveDirection::Left;
	case 2:
		return game::MoveDirection::TopLeft;
	case 3:
		return game::MoveDirection::DownLeft;
	default:
		throw new std::exception("failed to parse ball moving");
	}
}

game::MoveDirection game::Ball::getRightRandomDirection()
{
	srand(time(NULL));
	auto randomDirection = rand() % 3 + 1;

	switch (randomDirection)
	{
	case 1:
		return game::MoveDirection::Right;
	case 2:
		return game::MoveDirection::TopRight;
	case 3:
		return game::MoveDirection::DownRight;
	default:
		throw new std::exception("failed to parse ball moving");
	}
}