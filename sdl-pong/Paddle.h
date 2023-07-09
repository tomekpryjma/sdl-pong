#pragma once

#include <SDL.h>
#include "Vec2.h"
#include "globals.h"
#include "Clock.h"
#include <iostream>

class Paddle
{
protected:
	float yPos = 0;
	float speed = 300;
public:
	SDL_Rect rect;
	SDL_Color color;
	SDL_Renderer* renderer = nullptr;

	Paddle(){};
	Paddle(int x, int y, SDL_Renderer* appRenderer);

	void boundsCheck();
	void update(Vec2 ballPosition, Vec2 ballDirection);
	void draw();
	void move(float targetY);
};

