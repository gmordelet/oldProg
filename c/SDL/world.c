#include<stdio.h>
#include<math.h>
#include"objects.h"
#include"world.h"
#include"SDL.h"

#define MAX_OBJECTS 100

Object world[MAX_OBJECTS];
unsigned int objectNumber = 0;

unsigned int GetObjectNumber(void)
{
  return objectNumber;
}

void AddObject(Object o)
{
  if(objectNumber < MAX_OBJECTS)
    world[objectNumber++] = o;
}

Object *GetObject(unsigned int i)
{
  if(i >= objectNumber)
    return NULL;

  return &world[i];
}

extern int quit;

void UpdateWorld(unsigned int dt, int maxX, int maxY)
{
  SDL_Event event;
  int i;
  
  while(SDL_PollEvent(&event))
    if(event.type == SDL_QUIT)
      quit = 1;

  for(i = 0; i < objectNumber; ++i)
    {
      switch(world[i].type)
	{
	case BALL : 
	  MoveBall(&world[i], dt, maxX, maxY);
	  break;
	}
    }
}

void MoveBall(Object *object, unsigned int dt, int maxX, int maxY)
{
  int newDt, dtDt;
  float oldX, oldY;
  int in = object->ball.x - object->ball.radius >= 0
    && object->ball.x + object->ball.radius <= maxX
    && object->ball.y - object->ball.radius >= 0
    && object->ball.y + object->ball.radius <= maxY;


  oldX = object->ball.x;
  oldY = object->ball.y;
  object->ball.x += (float)cos(object->ball.movement.angle) * object->ball.movement.speed * dt;
  object->ball.y -= (float)sin(object->ball.movement.angle) * object->ball.movement.speed * dt;

  if(in){
    if(object->ball.x - object->ball.radius < 0)
      {
	dtDt = sqrt(0);
	object->ball.x = 0;
	object->ball.y = 0;
	object->ball.movement.angle = M_PI - object->ball.movement.angle;
      }

    if(object->ball.y - object->ball.radius < 0)
      {
	object->ball.movement.angle = - object->ball.movement.angle;
      }

    if(object->ball.x + object->ball.radius > maxX)
      {
	object->ball.movement.angle = M_PI - object->ball.movement.angle;
      }

    if(object->ball.y + object->ball.radius > maxY)
      {
	object->ball.movement.angle = - object->ball.movement.angle ;
      }
  }
}

float Modulo2Pi(float x)
{
  float d = x / (2 * M_PI);
  
  return (d - (int)d) * 2 * M_PI;
}
