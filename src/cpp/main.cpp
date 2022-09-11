
#include "../header/Functions.h"

int main(int args, char* argv[])
{
	// set up our window and a few resources we need
	slWindow(400, 400, "I´m in Misery", false);
	//slSetFont(slLoadFont("../Assets/secret.TTF"), 24);
	//slSetTextAlign(SL_ALIGN_CENTER);
	int tex = slLoadTexture("../Assets/secret4.png");
	int y = 0;
	int x = 0;
	int z = 40;
	float timeUntil = 5.0f;
	bool changeScreen = false;
	Rectangle example = { 200,200,50,50 };
	Ball ball= {100, 200, 50};
	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{

		if (slGetKey('W'))
		{
			y += 2;
		}
		if (slGetKey('S'))
		{
			y -= 2;
		}
		if (slGetKey('A'))
		{
			x -= 2;
		}
		if (slGetKey('D'))
		{
			x += 2;
		}
		if (slGetKey('Q'))
		{
			z -= 2;
		}
		if (slGetKey('E'))
		{
			z += 2;
		}
		// background glow

		slSprite(tex, x, y, z, z);
		slSetForeColor(1, 1, 1, 1);
		//slRectangleFill(x, y, z, z);
		if (timeUntil >= 0 && !changeScreen)
		{
			timeUntil -= slGetDeltaTime();

		}
		if (changeScreen && timeUntil < 0)
		{
			slClose();
			slWindow(800, 800, "Rompemotodo", false);
			changeScreen = false;
		}
		if (timeUntil < 0 && changeScreen)
		{
			changeScreen = true;
		}

		slSetBackColor(1, 1, 1);

		slSprite(tex, x, y, z, z);
		//slSetFontSize(24);
		//slText(200, 250, "Nacho:");
		slSetForeColor(0, 0, 1, 1);

		if (checkRecMouseCollision(example, getMousePosition()))
		{
			drawRectangle(example, BLUE);
		}
		else
		{
			drawRectangle(example, RED);
		}
		drawBall(ball,BLACK);


		slRender();

	}
	slClose();
	return 0;
}