#include "../header/GameLogic.h"

#include <cmath>

extern Ball ball;
void paddleBallLogic(Player player)
{
	if (checkRecBallCollision(player.pad,ball))
	{
		ball.position.y = player.pad.upEdge + ball.radius + 0.1f;
		ball.speed.x = abs(ball.speed.y);
		if (ball.position.x <= player.pad.leftEdge)
		{
			ball.speed.x  *= -1.0f;
		}
		else if (ball.position.x>player.pad.leftEdge && ball.position.x < player.pad.x)
		{
			ball.speed.x *= -(ball.position.x / player.pad.x);
		}
		else if (ball.position.x>player.pad.x && ball.position.x < player.pad.rightEdge)
		{
			ball.speed.x *= -(ball.position.x / player.pad.rightEdge);
		}
		else if (ball.position.x >= player.pad.rightEdge)
		{
			ball.speed.x *= 1.0f;
		}
		ball.speed.y *= -1.0f;
	}
}

void ballLogic()
{
	ball.position.x += ball.speed.x* slGetDeltaTime();
	ball.position.y += ball.speed.y* slGetDeltaTime();
}

void blockCheck()
{
}

void blockCollision()
{
}

void wallCollision()
{
	if (ball.position.y >=900- ball.radius)
	{
		ball.position.y = 900 - ball.radius - 0.02f;
		ball.speed.y *= -1.0f;
	}
	if (ball.position.y < ball.radius)
	{
		ball.position.y =  ball.radius +0.02f;
		ball.speed.y *= -1.0f;
	}
	if (ball.position.x < ball.radius)
	{
		ball.position.x = ball.radius + 0.02f;
		ball.speed.x *= -1.0f;
	}
	if (ball.position.x > 900 - ball.radius)
	{
		ball.position.x = 900 - ball.radius - 0.02f;
		ball.speed.x  *= -1.0f;
	}


}

void floorCollision()
{
}

void gameLogic()
{
}

void drawGame()
{
}
