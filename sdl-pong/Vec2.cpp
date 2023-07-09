#include "Vec2.h"

Vec2::Vec2()
{
	x = 0;
	y = 0;
}

Vec2::Vec2(float xPos, float yPos)
{
	x = xPos;
	y = yPos;
}

void Vec2::normalise()
{
	int magnitude = sqrt(pow(x, 2) + pow(y, 2));

	if (magnitude == 0) {
		return;
	}

	x /= magnitude;
	y /= magnitude;
}