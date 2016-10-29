#ifndef WORLD_H
#define WORLD_H

#include"objects.h"

unsigned int GetObjectNumber(void);
void AddObject(Object);
Object *GetObject(unsigned int);
void UpdateWorld(unsigned int, int, int);
void MoveBall(Object *, unsigned int, int, int);
float Modulo2Pi(float);

#endif
