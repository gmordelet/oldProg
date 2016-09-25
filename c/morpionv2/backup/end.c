//end.c

#include"headers.h"

int no_win(char mor[])
//le plateau est plein, personne n'a gagné
{
  int i, free;
  i = free = 0;
  while(i<9)
    {
      if(mor[i] == 0)
	++free;
      ++i;
    }
  if(free == 0)
    return 1;
  return 0;
}

int win_player(char player, char mor[])
//victoire ou non du 'player'
{
  int i;
  
  for(i=0;i<3;++i)
    {
      if((mor[3*i] == player) && (mor[3*i+1] == player) && (mor[3*i+2] == player))
	return 1;
    }
  for(i=0;i<3;++i)
    {
      if((mor[i] == player) && (mor[i+3] == player) && (mor[i+6] == player))
	return 1;
    }
  if((mor[0] == player) && (mor[4] == player) && (mor[8]))
    return 1;
  if((mor[2] == player) && (mor[4] == player) && (mor[6] == player))
    return 1;
  return 0;
}

