#pragma once

#include <SDL.h>
#include "Vec2.h"
#include "Clock.h"
#include "Paddle.h"
#include "globals.h"
#include "Player.h"
#include "Scoring.h"

class Ball
{
private:
	float speed = 150;
	Vec2 position;
	Vec2 initialPosition;
	Vec2 direction;
	SDL_Rect rect;
	SDL_Renderer* renderer;
	std::shared_ptr<Player> &paddle1;
	std::shared_ptr<Paddle> &paddle2;
	Scorer scorer = Scorer::NONE;

public:
	Ball(int x, int y, std::shared_ptr<Player> &pad1, std::shared_ptr<Paddle> &pad2, SDL_Renderer* appRenderer);

	void checkBounds();
	void checkCollision(SDL_Rect other);
	void update();
	void draw();
	Vec2 getPosition();
	Vec2 getDirection();
	Scorer getScorer();
	void resetAfterScore();
	void startMoving();
};

