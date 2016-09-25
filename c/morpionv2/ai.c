//ai.c
//contient l'intelligence artificielle

#include"headers.h"

#define DRAW 2
#define WIN 1
#define LOSE -1

int ai_init(char mor[], char ai_player)
{
  t_test init_test;
  return ai(mor, ai_player, ai_player, 0, &init_test);
}

int ai(char mor[], char ai_player,char turn_player, int turn, t_test *test)
//ai_player = signe de l'ai
//turn_player = signe de joueur de l'itération
//turn = nombre de tour en le premier lancement de la fonction et ses itérations
{
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
      test_tab[i].end = 0;
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
	  else
	    {
	      test_tab[i].turn = -1;
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
	  else
	    {
	      test_tab[i].turn = -1;
	    }
	}
    }
  return best_sol(test_tab,test);
}

int best_sol(t_test test_tab[], t_test *test)
{
  int min_draw, min_lose, min_win, move_min_win, move_min_lose, move_min_draw;
  int i;
  min_draw = 104;
  min_lose = 102;
  min_win = 103; 
  for(i=0; i<9; ++i) 
    {
      if(test_tab[i].turn != -1)
	{
	  if(test_tab[i].end == WIN && test_tab[i].turn < min_win)
	    {
	      min_win = test_tab[i].turn;
	      move_min_win = i;
	    }
	  if(test_tab[i].end == LOSE && test_tab[i].turn < min_lose)
	    {
	      min_lose = test_tab[i].turn;
	      move_min_lose = i;
	    }
	  if(test_tab[i].end == DRAW && test_tab[i].turn < min_draw)
	    {
	      min_draw = test_tab[i].turn;
	      move_min_draw = i;
	    }
	}
    }

  if(min_win <= min_draw && min_win <= min_lose)
    {
      test->end = WIN;
      test->turn = min_win;
      return move_min_win;
    }
  else if (min_lose < min_win && min_draw <= min_lose)
    {
      test->end = DRAW;
      test->turn = min_draw;
      return move_min_draw;
    }
}
