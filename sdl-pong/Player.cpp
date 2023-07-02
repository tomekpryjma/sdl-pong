#include "Player.h"

void Player::update(const Uint8* keyStates)
{
	int direction = 0;

	if (keyStates[SDL_SCANCODE_UP]) {
		direction = -1;
	}

	if (keyStates[SDL_SCANCODE_DOWN]) {
		direction = 1;
	}

	yPos += direction * Clock::delta * speed;

	Paddle::boundsCheck();

	rect.y = (int)yPos;
}