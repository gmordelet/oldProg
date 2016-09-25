//ai.h

#ifndef DEF_AI
#define DEF_AI

typedef struct t_test t_test;
struct t_test
{
  int turn;
  int end;
};

int ai_init(char mor[], char ai_player);
int ai(char mor[], char ai_player,char turn_player, int turn, t_test *test);


#endif
