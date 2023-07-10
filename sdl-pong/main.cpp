#include "App.h"
#include "Paddle.h"
#include "Player.h"
#include "Ball.h"
#include "Scoring.h"

int main(int argc, char* args[]) {
	srand(time(NULL));

	App app;
	Scoring scoring;
	int midPointY = HEIGHT / 2;
	std::shared_ptr<Player> pPlayer = std::shared_ptr<Player>(
		new Player(20, midPointY - PADDLE_HEIGHT / 2, app.getRenderer()));
	std::shared_ptr<Paddle> pPaddle = std::shared_ptr<Paddle>(
		new Paddle(WIDTH - 20, midPointY - PADDLE_HEIGHT / 2, app.getRenderer()));

	Ball ball(
		WIDTH / 2 - BALL_SIZE / 2,
		midPointY - BALL_SIZE / 2,
		pPlayer,
		pPaddle,
		app.getRenderer()
	);

	app.loop(pPlayer, pPaddle, ball, scoring);
	app.quit();
	return 0;
}