#pragma once
#include "GameConfig.h"
#include "Types.h"

namespace game
{
	class Ball
	{
		public:
			Ball();
			Ball(const game::Point startPoint);
			const game::Point getPos();
			void updatePos();
			void changeVerticalDirection();
			void changeHorizontalDirection();
		private:
			game::MoveDirection getTopRandomDirection();
			game::MoveDirection getDownRandomDirection();
			game::MoveDirection getLeftRandomDirection();
			game::MoveDirection getRightRandomDirection();

		private:
			game::Point m_currentPoint;
			game::MoveDirection m_currentDirection;
	};
}


