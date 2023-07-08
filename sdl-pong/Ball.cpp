#include "Ball.h"

Ball::Ball(int x, int y, std::shared_ptr<Player> &pad1, std::shared_ptr<Paddle> &pad2, SDL_Renderer* appRenderer)
	: paddle1(pad1), paddle2(pad2)
{
	rect.x = x;
	rect.y = y;
	rect.w = BALL_SIZE;
	rect.h = BALL_SIZE;
	renderer = appRenderer;
	direction.x = 1;
	direction.y = 0;
	position.x = x;
	position.y = y;
}

void Ball::update()
{
	position.x += direction.x * speed * Clock::delta;
	position.y += direction.y * speed * Clock::delta;
	checkBounds();
	checkCollision(paddle1->rect);
	checkCollision(paddle2->rect);
	rect.x = position.x;
	rect.y = position.y;
}

void Ball::draw()
{
	SDL_RenderDrawRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

#if DEBUG_MODE
	SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.x + (15 * direction.x), rect.y + (10 * direction.y));
#endif
}

void Ball::checkBounds()
{
	if (rect.y < 0) {
		direction.y = 1;
	}
	else if (rect.y > HEIGHT) {
		direction.y = -1;
	}
}

void Ball::checkCollision(SDL_Rect other)
{
	if (
		rect.x < other.x + other.w
		&& rect.x + rect.w > other.x
		&& rect.y < other.y + other.h
		&& rect.y + rect.h > other.y
	) {
		if (rect.x < other.x) {
			direction.x = -1;
		} else {
			direction.x = 1;
		}

		if (rect.y + BALL_SIZE / 2 < other.y + PADDLE_HEIGHT / 2) {
			direction.y = -1;
		}
		else {
			direction.y = 1;
		}
	}
}

Vec2 Ball::getPosition()
{
	return position;
}

Vec2 Ball::getDirection()
{
	return direction;
}