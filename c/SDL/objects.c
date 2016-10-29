#include"objects.h"

Object MakeBall(float x, float y, unsigned int radius)
{
  Object ball;

  ball.type = BALL;
  ball.ball.x = x;
  ball.ball.y = y;
  ball.ball.radius = radius;

  return ball;
}
