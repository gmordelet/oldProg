//headers.h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"visual.h"
//#include"turn.h"
//#include"end.h"
//#include"ai.h"
 
typedef struct t_test t_test;
struct t_test
{
  int turn;
  int end;
};

int ai(char mor[], char ai_player,char turn_player, int turn, t_test *test);
