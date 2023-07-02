#include "Clock.h"

float Clock::delta = 0;
Uint32 Clock::now = 0;
Uint32 Clock::last = 0;

void Clock::tick()
{
	Clock::delta = (float)(Clock::now - Clock::last) / 1000.0;
	Clock::last = Clock::now;
	Clock::now = SDL_GetTicks();
}
