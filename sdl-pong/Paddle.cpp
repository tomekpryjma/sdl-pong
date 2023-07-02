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
// @TODO: Fix paddle trajectory movement based on ball position.
void Paddle::update(Vec2 ballPosition, Vec2 ballDirection)
{
	if (ballDirection.x != 1) {
		return;
	}

	float denominator = (ballPosition.x + ballDirection.x) - ballPosition.x;

	if (denominator == 0) {
		return;
	}

	float ballBottom = ballPosition.y + BALL_SIZE;
	float ballRight = ballPosition.x + BALL_SIZE;

	float m = ((ballBottom + ballDirection.y) - ballBottom) / abs((int)denominator);
	float yIntercept = (HEIGHT - ballBottom) - (m * (WIDTH - ballRight));
	rect.y = abs((int)yIntercept - BALL_SIZE);
}

void Paddle::draw()
{
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	SDL_RenderDrawRect(renderer, &rect);
}