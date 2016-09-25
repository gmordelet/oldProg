#include"matrix.h"

SurfaceMatrix MakeSurfaceMatrix(SDL_Surface *surface)
{
  int width, height, x, y;
  SurfaceMatrix surfaceMatrix;
  Uint32 ***matrix;

  width = surface->w;
  height = surface->h;
  matrix = (Uint32 ***)malloc(sizeof(Uint32 **) * (width));

  for(x = 0; x < width; ++x)
    {
      matrix[x] = (Uint32 **)malloc(sizeof(Uint32 *) * height);
      for(y = 0; y < height; ++y)
	  matrix[x][y] = (Uint32 *)((Uint8 *)surface->pixels + sizeof(Uint32) * x + y * surface->pitch);
    }

  surfaceMatrix.width = width;
  surfaceMatrix.height = height;
  surfaceMatrix.matrix = matrix;
  surfaceMatrix.surface = surface;

  return surfaceMatrix;
}

void PutPixel(SurfaceMatrix matrix, int x, int y, int color)
{
  if(x < 0 || x > (matrix.width - 1)
     || y < 0 || y > (matrix.height - 1))
      return;

  *(matrix.matrix[x][y]) = color;
}
