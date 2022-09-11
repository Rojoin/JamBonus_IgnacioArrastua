#include "../../src/header/Functions.h"
#include <cmath>
#include "sl.h"

Ball ball;
Vector2 getMousePosition()
{
	int x = slGetMouseX();
	int y = slGetMouseY();

	return { x,y };
}

void drawBall(Ball ball,Color color)
{

	slSetForeColor(color.r, color.g, color.b, color.a);
	slCircleFill(ball.x, ball.y, ball.radius, 100);
}
void drawRectangle(Rectangle rectangle, Color color)
{
	slSetForeColor(color.r, color.g, color.b, color.a);
	slRectangleFill(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
}
bool checkRecBallCollision(Rectangle rectangle)
{

	float testX = ball.x;
	float testY = ball.y;

	if (ball.x < rectangle.x)
	{
		testX = rectangle.x;
	}
	else if (ball.x > rectangle.x + rectangle.width)
	{
		testX = rectangle.x + rectangle.width;
	}
	if (ball.y < rectangle.y)
	{
		testY = rectangle.y;
	}
	else if (ball.y > rectangle.y + rectangle.height)
	{
		testY = rectangle.y + rectangle.height;
	}

	float distanceX = ball.x - testX;
	float distanceY = ball.y - testY;
	float distance = sqrt((distanceX * distanceX) + (distanceY * distanceY));

	if (distance <= ball.radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool checkRecMouseCollision(Rectangle rec, Vector2 mouse)
{
	int rightEdge = rec.x + rec.width / 2;
	int leftEdge = rec.x - rec.width / 2;
	int upEdge = rec.y - rec.height / 2;
	int downEdge = rec.y + rec.height / 2;

	if (mouse.x >= leftEdge && mouse.x <= rightEdge && mouse.y >= upEdge && mouse.y <= downEdge)
	{
		return true;
	}
	else
	{
		return false;
	}
}





