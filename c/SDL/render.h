#ifndef RENDER_H
#define RENDER_H

#include"SDL.h"
#include"matrix.h"

typedef struct{
  int x, y;
}Point;

void InitRender(SurfaceMatrix);
void PutPixelRender(SurfaceMatrix, unsigned int, unsigned int, unsigned int);
void Render(SurfaceMatrix);
void RemoveOldPixels(SurfaceMatrix);
void DrawObject(SurfaceMatrix, Object);
void DrawBall(SurfaceMatrix, Object, unsigned int);
void DrawCircle(SurfaceMatrix, int, int, int, unsigned int);
void DrawLine(SurfaceMatrix, int, int, int, int, unsigned int);

#endif
