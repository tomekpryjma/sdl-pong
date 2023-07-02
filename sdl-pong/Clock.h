#pragma once

#include <SDL.h>

class Clock
{
public:
	static float delta;
	static Uint32 now;
	static Uint32 last;

	static void tick();
};

