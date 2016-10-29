#ifndef OBJECTS_H
#define OBJECTS_H

#define BALL 1

typedef struct{
  int direction;
  int speed;
}Movement;

typedef struct{
  int type;
  int x, y, size;
  Movement v;
}Object;

#endif
