#include<stdio.h>
#include"objects.h"
#include"world.h"

#define MAX_OBJECTS 50

Object world[MAX_OBJECTS];
int objectNumber = 0;

int GetObjectNumber(void)
{
  return objectNumber;
}

void AddObject(Object o)
{
  world[objectNumber++] = o;
}

Object *GetObject(int i)
{
  if(i >= objectNumber)
    return NULL;

  return &world[i];
}


