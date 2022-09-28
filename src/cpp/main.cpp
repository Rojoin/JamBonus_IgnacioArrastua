
#include <iostream>

#include "../header/Functions.h"
#include "../header/GameLogic.h"
#include "../header/InputSystem.h"

int main(int args, char* argv[])
{
	// set up our window and a few resources we need
	slWindow(900, 900, "I´m in Misery", false);
	//slSetFont(slLoadFont("../Assets/secret.TTF"), 24);
	//slSetTextAlign(SL_ALIGN_CENTER);
	int tex = slLoadTexture("../Assets/secret4.png");
	extern Ball ball;
	Vector2 pos = {100,200};
	Vector2 speed = {200,250};
	ball.radius = 50;
	ball.position = pos;
	ball.speed = speed;
	Player player = { 450,100,25,25 };
	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{

		updatePadParts(player.pad);
		int speed = 10;
		double test = slGetDeltaTime();
		if (slGetKey('A') && player.pad.leftEdge > 0)
		{

			player.pad.x -= speed *0.16f;
		}
		if (slGetKey('Q') && player.pad.rightEdge < 900)
		{
			player.pad.x += speed * 0.16f;
		}

		std::cout << player.pad.x;
	
		/*ballLogic();
		wallCollision();
		drawBall(ball,RED);*/
		drawRectangle(player.pad, WHITE);

		slRender();

	}
	slClose();
	return 0;
}