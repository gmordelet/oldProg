#ifndef DEF_MATRIX
#define DEF_MATRIX

#include"SDL.h"

typedef struct SurfaceMatrix SurfaceMatrix;
struct SurfaceMatrix {
  Uint32 ***matrix;
  int width;
  int height;
  SDL_Surface *surface;
};

SurfaceMatrix MakeSurfaceMatrix(SDL_Surface *);
void PutPixel(SurfaceMatrix, int, int, int);

#endif
