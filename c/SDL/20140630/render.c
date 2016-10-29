#include<stdio.h>
#include"objects.h"
#include"render.h"
#include"matrix.h"

#define BACKGROUND_COLOR 0xFFFFFFFF
#define OBJECTS_COLOR 0

typedef struct{
  int x, y;
}Point;

Point *drawnPixels = NULL;
int numberDrawnPixels = 0;

void InitRender(SurfaceMatrix matrix)
{
  int x, y;

  drawnPixels = (Point *)malloc(sizeof(Point) * matrix.width * matrix.height);
  for(x = 0; x < matrix.width; ++x)
    for(y = 0; y < matrix.height; ++y)
      PutPixel(matrix, x, y, BACKGROUND_COLOR);  
}

void PutPixelRender(SurfaceMatrix matrix, int x, int y, int color)
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
  int x;

  switch(object.type)
    {
    case BALL :
      DrawBall(matrix, object);
    }
}

void DrawBall(SurfaceMatrix matrix, Object object)
{
  PutPixelRender(matrix, object.x, object.y, OBJECTS_COLOR);
  while(object.size > 0)
    {
      DrawCircle(matrix, object.x, object.y, object.size--);
    }
}

void DrawCircle(SurfaceMatrix matrix, int x0, int y0, int r) 
{
  int x, y, d;

  x = 0;
  y = r;
  d = r - 1;
  while(y >= x)
    {
      PutPixelRender(matrix, x0 + x, y0 + y, OBJECTS_COLOR);
      PutPixelRender(matrix, x0 + y, y0 + x, OBJECTS_COLOR);
      PutPixelRender(matrix, x0 - x, y0 + y, OBJECTS_COLOR);
      PutPixelRender(matrix, x0 - y, y0 + x, OBJECTS_COLOR);
      PutPixelRender(matrix, x0 + x, y0 - y, OBJECTS_COLOR);
      PutPixelRender(matrix, x0 + y, y0 - x, OBJECTS_COLOR);
      PutPixelRender(matrix, x0 - x, y0 - y, OBJECTS_COLOR);
      PutPixelRender(matrix, x0 - y, y0 - x, OBJECTS_COLOR);
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

void RemoveOldPixels(SurfaceMatrix matrix)
{
  int i;
  
  for(i = 0; i < numberDrawnPixels; ++i)
    PutPixel(matrix, drawnPixels[i].x, drawnPixels[i].y, BACKGROUND_COLOR);

  numberDrawnPixels = 0;
}
