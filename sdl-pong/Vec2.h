#pragma once

#include <cmath>

class Vec2
{
public:
	float x;
	float y;

	Vec2();
	Vec2(float xPos, float yPos);
	void normalise();
};

