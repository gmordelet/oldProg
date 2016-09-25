//turn.c

#include"headers.h"

int turn(char mor[])
//tour de jeu, retourne 1 tant que la partie continue
{
  int horizontal, vertical, move;
  int retry = 1; //pour redemander les coordonnées si le coup n'est pas valide
  int a;
  while(retry)
    {
      printf("X ?\n");
      printf("Horizontal ? ");
      scanf("%d",&horizontal);
      printf("Vertical ? ");
      scanf("%d",&vertical);
      
      if(!valid_move(horizontal, vertical, mor))
	{
	  printf("Coups invalide, recommencez\n");
	  break;
	}
      mor[(3*(horizontal-1)) + (vertical-1)] = 'X';
      print_board(mor);
      if(win_player('X', mor))
	{
	  printf("Fin de partie. Victoire du joueur X\n");
	  return 0;
	}
      if(no_win(mor))
	{
	  printf("Fin de partie. Personne n'a gagné\n");
	  return 0;
	}
      retry = 0;
    }

  retry = 1;
  
typedef struct t_test t_test;
struct t_test
{
  int turn;
  int end;
};

 printf("coup AI = %d",ai_init(mor,'O'));
 a = ai_init(mor,'O');
 // mor[a] = '0';
// mor[ai_init(mor,'O')] = 'O';
 print_board(mor);

  retry = 0;

  /*  while(retry)
    {
      printf("O ?\n");
      printf("Horizontal ? ");
      scanf("%d",&horizontal);
      printf("Vertical ? ");
      scanf("%d",&vertical);
      
      if(!valid_move(horizontal, vertical, mor))
	{
	  printf("Coups invalide, recommencez\n");
	  break;
	}
      mor[(3*(horizontal-1)) + (vertical-1)] = 'O';
      print_board(mor);
      if(win_player('O', mor))
	{
	  printf("Fin de partie. Victoire du joueur O\n");
	  return 0;
	}
      retry = 0;
      }*/

  return 1;
}

int valid_move(int horizontal, int vertical, char mor[])
//validité du coups joué
{
  if(!(((horizontal>0) && (horizontal<4)) && ((vertical>0) && (vertical < 4))))
    return 0;

  if(mor[(3*(horizontal-1)) + (vertical-1)] != 0)
    return 0;

  return 1;
}
