#ifndef RENDER_H
#define RENDER_H

#include"SDL.h"
#include"matrix.h"

void InitRender(SurfaceMatrix);
void PutPixelRender(SurfaceMatrix, int, int, int);
void Render(SurfaceMatrix);
void RemoveOldPixels(SurfaceMatrix);
void DrawObject(SurfaceMatrix, Object);
void DrawBall(SurfaceMatrix, Object);
void DrawCircle(SurfaceMatrix, int, int, int) ;

#endif
