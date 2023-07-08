#include "Paddle.h"

Paddle::Paddle(int x, int y, SDL_Renderer* appRenderer)
{
	rect.x = x;
	rect.y = y;
	yPos = y;
	rect.w = PADDLE_WIDTH;
	rect.h = PADDLE_HEIGHT;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	renderer = appRenderer;
}

void Paddle::boundsCheck()
{
	if (yPos < 0) {
		yPos = 0;
	} else if (yPos + PADDLE_HEIGHT > HEIGHT) {
		yPos = HEIGHT - PADDLE_HEIGHT;
	}

}

// TODO: Add margin of error for CPU paddle movement so it doesn't always hit the ball back.
void Paddle::update(Vec2 ballPosition, Vec2 ballDirection)
{
	// Don't bother running this calculation if the ball is going towards player.
	if (ballDirection.x < 0) {
		return;
	}

	float x1 = ballPosition.x + BALL_SIZE;
	float y1 = ballPosition.y + BALL_SIZE;
	float x2 = x1 + ballDirection.x;
	float y2 = y1 + ballDirection.y;
	float x3 = WIDTH;
	float y3 = 0;
	float x4 = WIDTH;
	float y4 = HEIGHT;
	float denominator = ((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4));

	if (denominator == 0) {
		return;
	}

	float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
	float u = ((x1 - x3) * (y1 - y2) - (y1 - y3) * (x1 - x2)) / denominator;

	/**
	* Ball trajectory to right-side of screen happens when the below is true.
	*/
	if (u >= 0 && u <= 1) {
		yPos = (y3 + u * (y4 - y3)) - BALL_SIZE * 2;
		rect.y = yPos;
	}
}

void Paddle::draw()
{
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	SDL_RenderDrawRect(renderer, &rect);
}