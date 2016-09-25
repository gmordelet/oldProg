//triabul.c

#include<stdio.h>
#include<stdlib.h>

#define TAILLE 100

void echange(int * a, int * b)
{
  *a+=*b;
  *b=*a-*b;
  *a-=*b;
}

int rand_n(int min, int max)
{
  return(rand()%(max-min+1)+min);
}

void tab_rand(int tab[TAILLE])
{
  int i=0;
  while(i<TAILLE)
    {
      tab[i]=rand_n(0,100000);
      i++;
    }
}

void triabul(int tab[TAILLE])
{
  int i=1,j,t=0;
  while(i<TAILLE)
    {
      j=0;
      while(j<TAILLE-t-1)
	{	  
	  if(tab[j]<tab[j+1])
	    {
	    echange(&tab[j],&tab[j+1]);
	    }
	  ++j;
	}
      ++t;
      ++i;
    }
}

void affich_tab(int tab[TAILLE])
{
  int i=0;
  while(i<TAILLE)
    {
      printf("%d\n",tab[i]);
      ++i;
    }
}

int main()
{
  srand(time(NULL));
  int tab[TAILLE];
  tab_rand(tab);
  triabul(tab);
  affich_tab(tab);

  return 0;
}






