#pragma once

#include <SDL.h>
#include <iostream>
#include "Paddle.h"
#include "Clock.h"

class Player :
	public Paddle
{
	using Paddle::Paddle;

public:
	void update(const Uint8* keyStates);
};

