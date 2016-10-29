#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"SDL.h"
#include"matrix.h"
#include"world.h"
#include"objects.h"

int quit = 0;

int main() 
{
  unsigned int width, height, currentTime, lastTime, dt, maxX, maxY;
  SDL_Surface *screen;
  SurfaceMatrix screenMatrix;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
      return 1;
    }

  width = 640;
  height = 480;
  printf("width = %d, heigth = %d\n", width, height);

  if((screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    {
      fprintf(stderr, "Erreur lors de l'initialisation de screen : %s\n", SDL_GetError());
      return 1;
    }

  screenMatrix = MakeSurfaceMatrix(screen);
  InitRender(screenMatrix);

  srand(time(NULL));  
  Object o = MakeBall(width / 2, height / 2, 10);
  o.ball.movement.speed  = 0.01;
  o.ball.movement.angle = 0;
  AddObject(o);
  maxX = width - 1;
  maxY = height - 1;

  lastTime = SDL_GetTicks();

  while(!quit)
    {
      currentTime = SDL_GetTicks();
      dt = currentTime - lastTime;
      UpdateWorld(dt, maxX, maxY);
      Render(screenMatrix);
      lastTime = currentTime;
    }

  SDL_Quit();

  return 0;
}
