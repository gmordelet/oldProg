//ai.c
//contient l'intelligence artificielle

#include"headers.h"

#define WIN 1
#define LOSE -1
#define DRAW 0

/*typedef struct t_test t_test;
struct t_test
{
  int turn;
  int end;
};
*/

int ai(char mor[], char ai_player,char turn_player, int turn, t_test *test)
//ai_player = signe de l'ai
//turn_player = signe de joueur de l'itération
//turn = nombre de tour en le premier lancement de la fonction et ses itérations
{
  printf("test\n");
  char mor_test[9];
  t_test test_tab[9];
  int i;
  char opponent = (ai_player == 'X') ? 'O' : 'X';
  
  if(no_win(mor))
    {
      (*test).end = DRAW;
      (*test).turn = turn;
      return;
    }

  if(win_player(ai_player,mor))
    {
      (*test).end = WIN;
      (*test).turn = turn;
      return;
    }
    
  if(win_player(opponent,mor))
    {
      (*test).end = LOSE;
      (*test).turn = turn;
      return;
    }

  for(i=0; i<9; ++i)
    mor_test[i] = mor[i];

  for(i=0; i<9; ++i)
    {
      test_tab[i].turn = 100;//valeur inatteignable
    }
  
  if(ai_player == turn_player)
    {
      for(i=0; i<9; ++i)
	{
	  if(mor[i] == 0)
	    {
	      mor_test[i] = ai_player;
	      ai(mor_test, ai_player, opponent, turn+1, &test_tab[i]);
	      mor_test[i] = 0;
	    }
	}
    }
  else
    {
      for(i=0; i<9; ++i)
	{
	  if(mor[i] == 0)
	    {
	      mor_test[i] = opponent;
	      ai(mor_test, ai_player, ai_player, turn+1, &test_tab[i]);
	      mor_test[i] = 0;
	    }
	}
    }
  int min_move, min_turn;
  //point à améliorer, prendre LOSE en compte avec un min_move_lose...devra être totalement refaite
  //un min_move_win min_move_draw min_turn_win...
  for(i=0; i<9; ++i)
    {
      if(test_tab[i].turn < min_turn)
	{
	  min_move = i;
	  continue;
	}
      if((test_tab[i].turn == min_turn) && test_tab[i].end == WIN)
	{
	  min_move = i;
	  continue;
	}
      
	
    }
  if(turn == 0)
    return min_move;
}
