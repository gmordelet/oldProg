#include<stdio.h>
#include"objects.h"
#include"render.h"
#include"matrix.h"

#define BACKGROUND_COLOR 0xFFFFFFFF
#define OBJECTS_COLOR 0

Point *drawnPixels = NULL;
unsigned int numberDrawnPixels = 0;

void InitRender(SurfaceMatrix matrix)
{
  int x, y;

  drawnPixels = (Point *)malloc(sizeof(Point) * matrix.width * matrix.height);
  for(x = 0; x < matrix.width; ++x)
    for(y = 0; y < matrix.height; ++y)
      PutPixel(matrix, x, y, BACKGROUND_COLOR);  
}

void PutPixelRender(SurfaceMatrix matrix, unsigned int x, unsigned int y, unsigned int color)
{
  Point point;
  int i;

  PutPixel(matrix, x, y, color);

  for(i = 0; i < numberDrawnPixels; ++i)
    if(drawnPixels[i].x == x && drawnPixels[i].y == y)
      return;

  point.x = x;
  point.y = y;
  drawnPixels[numberDrawnPixels++] = point;
}

void Render(SurfaceMatrix matrix)
{
  int i, objectNumber;
  Object *object;

  RemoveOldPixels(matrix);
  
  objectNumber = GetObjectNumber();

  for(i = 0; i < objectNumber; ++i)
    if((object = GetObject(i)) != NULL)
	DrawObject(matrix, *object);

  SDL_Flip(matrix.surface);
}

void DrawObject(SurfaceMatrix matrix, Object object)
{
  switch(object.type)
    {
    case BALL :
      DrawBall(matrix, object, OBJECTS_COLOR);
    }
}

void DrawBall(SurfaceMatrix matrix, Object object, unsigned int color)
{
  PutPixelRender(matrix, object.ball.x, object.ball.y, color);
  while(object.ball.radius > 0)
    DrawCircle(matrix, (int)object.ball.x, (int)object.ball.y, object.ball.radius--, color);
}

void DrawCircle(SurfaceMatrix matrix, int x0, int y0, int r, unsigned int color) 
{
  int x, y, d;

  x = 0;
  y = r;
  d = r - 1;

  while(y >= x)
    {
      PutPixelRender(matrix, x0 + x, y0 + y, color);
      PutPixelRender(matrix, x0 + y, y0 + x, color);
      PutPixelRender(matrix, x0 - x, y0 + y, color);
      PutPixelRender(matrix, x0 - y, y0 + x, color);
      PutPixelRender(matrix, x0 + x, y0 - y, color);
      PutPixelRender(matrix, x0 + y, y0 - x, color);
      PutPixelRender(matrix, x0 - x, y0 - y, color);
      PutPixelRender(matrix, x0 - y, y0 - x, color);

      if(d >= 2 * x)
	{
	  d -= 2 * x + 1;
	  ++x;
	}
      else if(d < 2 * (r - y))
	{
	  d += 2 * y - 1;
	  --y;
	}
      else
	{
	  d += 2 * (y - x - 1);
	  --y;
	  ++x;
	}
    }
}

void DrawLine(SurfaceMatrix matrix, int x1, int x2, int y1, int y2, unsigned int color)
{
  int dx, dy, i, xinc, yinc, cumul, x, y;

  x = x1;
  y = y1;
  dx = x2 - x1;
  dy = y2 - y1;
  xinc = ( dx > 0 ) ? 1 : -1;
  yinc = ( dy > 0 ) ? 1 : -1;
  dx = abs(dx);
  dy = abs(dy);
  PutPixelRender(matrix, x, y, color);

  if ( dx > dy ) 
    {
      cumul = dx / 2;
      for ( i = 1 ; i <= dx ; i++ )
	{
	  x += xinc;
	  cumul += dy;
	  if ( cumul >= dx ) 
	    {
	      cumul -= dx;
	      y += yinc;
	    }
	  PutPixelRender(matrix, x, y, color);
	}
    }
  else 
    {
      cumul = dy / 2;
      for ( i = 1 ; i <= dy ; i++ ) 
	{
	  y += yinc;
	  cumul += dx;
	  if ( cumul >= dy ) 
	    {
	      cumul -= dy;
	      x += xinc; 
	    }
	  PutPixelRender(matrix, x, y, color);
	}
    }
}


void RemoveOldPixels(SurfaceMatrix matrix)
{
  int i;
  
  for(i = 0; i < numberDrawnPixels; ++i)
    PutPixel(matrix, drawnPixels[i].x, drawnPixels[i].y, BACKGROUND_COLOR);

  numberDrawnPixels = 0;
}
