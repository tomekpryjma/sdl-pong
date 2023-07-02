#include "App.h"

App::App()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		sdlError();
		quit(1);
	}

	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) != 0) {
		sdlError();
		quit(1);
	}

	isRunning = true;
}

void App::quit()
{
	shutdown();
	exit(0);
}
void App::quit(int status)
{
	shutdown();
	exit(status);
}

void App::sdlError()
{
	printf("%s", SDL_GetError());
}

void App::shutdown()
{
	SDL_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = nullptr;
	window = nullptr;
}

SDL_Renderer* App::getRenderer()
{
	return renderer;
}

void App::loop(std::shared_ptr<Player>& player, std::shared_ptr<Paddle>& paddle, Ball ball)
{
	SDL_Event e;

	while (isRunning) {
		Clock::tick();

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit();
			}
		}

		const Uint8* keyStates = SDL_GetKeyboardState(NULL);

		ball.update();
		player->update(keyStates);
		paddle->update(ball.getPosition(), ball.getDirection());

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		player->draw();
		paddle->draw();
		ball.draw();

		SDL_RenderPresent(renderer);
	}
}