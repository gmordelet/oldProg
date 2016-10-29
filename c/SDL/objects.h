#ifndef OBJECTS_H
#define OBJECTS_H

#define BALL 1

typedef struct{
  float angle;
  float speed;
}Movement;

typedef struct{
  int type;
  float  x, y;
  unsigned int radius;
  Movement movement;
}Ball;

typedef union{
  int type;
  Ball ball;
}Object;

Object MakeBall(float, float, unsigned int);

#endif
