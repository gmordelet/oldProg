//menu.c

#include "headers.h"


void menu(int ask)
{
  printf("/---------------------------------\\\n");
  printf("| Programme de conversion de base |\n");
  printf("\\---------------------------------/\n\n");

  int base1, base2;
  char input[MAX];
  char continu = 0;
  char fake;
  extern int in, out;

  memset(input,0,MAX);
  while(continu!='n' && continu!='N')
    {
      continu = 0;
      if(ask & ASKB1 != 0)
	{
	  printf("Base du nombre en entree ? ");
	  scanf("%d",&base1);
	}
      else
	{
	  base1 = in;
	}
      printf("Nombre en entre ? ");
      scanf("%s",input);
      if(!checking(input,base1))
	{
	  printf("Le nombre n est pas en base %d\n",base1);
   	}	
      else
	{
	  if(ask & ASKB2 != 0)
	    {
	      printf("convertir en base ? ");
	      scanf("%d",&base2);
	    }
	  else 
	    {
	      base2 = out;
	    }
	  print_base2(array_to_int(input,base1),base2);
	  printf("\n");
	}
      while(continu!='n' && continu!='N' && continu!='o' && continu!='O')
	{
	  scanf("%c",&fake);
	  printf("Continuer ? (O/N) ");
	  scanf("%c",&continu);
	}
      printf("\n");
    }
}



