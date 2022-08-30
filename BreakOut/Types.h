#pragma once

namespace game
{
	struct Point
	{
		int x;
		int y;

		bool isEqual(Point pos)const
		{
			return pos.x == this->x && pos.y == this->y;
		}
	};

	enum class MoveDirection
	{
		None = 0,
		Top,
		Down,
		Right,
		Left,
		TopRight,
		TopLeft,
		DownRight,
		DownLeft
	};
}