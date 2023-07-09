#include "Clock.h"

float Clock::delta = 0;
Uint32 Clock::last = SDL_GetTicks();

void Clock::tick()
{
	Uint32 current = SDL_GetTicks();
	float dt = (current - Clock::last) / 1000.0f;
	
	// Not sure if this is correct, seems like a hack...
	// TODO: Come back to this.
	if (dt > FPS_60_LIMIT) {
		dt = FPS_60_LIMIT;
	}

	Clock::delta = dt;
	Clock::last = current;
}
