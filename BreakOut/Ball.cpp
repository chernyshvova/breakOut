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

//void game::Ball::changeDirection()
//{
//	m_currentDirection = getRandomDirection();
//}

//game::MoveDirection game::Ball::getRandomDirection()
//{
//	switch (m_currentDirection)
//	{
//	case game::MoveDirection::Down:
//		return getDownRandomDirection();
//	case game::MoveDirection::DownLeft:
//		return getDownLeftRandomDirection();
//	case game::MoveDirection::DownRight:
//		return geDownRightRandomDirection();
//	case game::MoveDirection::Top:
//		return getTopRandomDirection();
//	case game::MoveDirection::TopLeft:
//		return getTopLeftRandomDirection();
//	case game::MoveDirection::TopRight:
//		return getTopRightRandomDirection();
//
//	default:
//		//TODO add exception
//		break;
//		return game::MoveDirection::Top;
//	}
//}

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
			//TODO add exception
			break;
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
		//TODO add exception
		break;
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
			//TODO add exception
			break;
			return game::MoveDirection::Top;
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
		//TODO add exception
		break;
		return game::MoveDirection::Top;
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
		//TODO add exception
		break;
		return game::MoveDirection::Top;
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
		//TODO add exception
		break;
		return game::MoveDirection::Top;
	}
}
//------------------

//game::MoveDirection game::Ball::getTopRightRandomDirection()
//{
//	srand(time(NULL));
//	auto randomDirection = rand() % 3 + 1;
//
//	switch (randomDirection)
//	{
//	case 1:
//		return game::MoveDirection::Left;
//	case 2:
//		return game::MoveDirection::TopLeft;
//	case 3:
//		return game::MoveDirection::DownLeft;
//	default:
//		//TODO add exception
//		break;
//		return game::MoveDirection::Top;
//	}
//}
//
//game::MoveDirection game::Ball::getTopLeftRandomDirection()
//{
//	srand(time(NULL));
//	auto randomDirection = rand() % 3 + 1;
//
//	switch (randomDirection)
//	{
//	case 1:
//		return game::MoveDirection::Right;
//	case 2:
//		return game::MoveDirection::TopRight;
//	case 3:
//		return game::MoveDirection::DownRight;
//	default:
//		//TODO add exception
//		break;
//		return game::MoveDirection::Top;
//	}
//}
//
//game::MoveDirection game::Ball::getDownLeftRandomDirection()
//{
//	srand(time(NULL));
//	auto randomDirection = rand() % 3 + 1;
//
//	switch (randomDirection)
//	{
//	case 1:
//		return game::MoveDirection::Right;
//	case 2:
//		return game::MoveDirection::TopRight;
//	case 3:
//		return game::MoveDirection::DownRight;
//	default:
//		//TODO add exception
//		break;
//		return game::MoveDirection::Top;
//	}
//}
//
//game::MoveDirection game::Ball::geDownRightRandomDirection()
//{
//	srand(time(NULL));
//	auto randomDirection = rand() % 3 + 1;
//
//	switch (randomDirection)
//	{
//	case 1:
//		return game::MoveDirection::Left;
//	case 2:
//		return game::MoveDirection::TopLeft;
//	case 3:
//		return game::MoveDirection::DownLeft;
//	default:
//		//TODO add exception
//		break;
//		return game::MoveDirection::Top;
//	}
//}