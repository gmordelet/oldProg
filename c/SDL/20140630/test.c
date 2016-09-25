#include<stdio.h>
#include"SDL.h"
#include"matrix.h"
#include"world.h"
#include"objects.h"

int main() 
{
  int width, height, x, y;
  SDL_Surface *screen;
  SDL_Event event;
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

  Object o = {BALL, 100, 100, 12, {0, 0}};
  AddObject(o);

  while(event.type != SDL_QUIT)
    {
      Render(screenMatrix);
      SDL_Flip(screen);
      SDL_WaitEvent(&event);
    }

  SDL_Quit();

  return 0;
}
