#pragma once

#include <SDL.h>
#include "globals.h"

class Clock
{
public:
	static float delta;
	static Uint32 last;

	static void tick();
};

