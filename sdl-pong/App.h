#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Paddle.h"
#include "Player.h"
#include "Clock.h"
#include "Ball.h"
#include "globals.h"
#include "Scoring.h"

class App
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;

public:
	App();

	void sdlError();
	void quit();
	void quit(int status);
	void shutdown();
	void loop(std::shared_ptr<Player> &player, std::shared_ptr<Paddle> &paddle, Ball ball, Scoring scoring);
	SDL_Renderer* getRenderer();
};

