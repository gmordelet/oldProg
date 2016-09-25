//formalismetableau.c

#include<stdio.h>

#define TAILLE 5

int main(){
  int tab[TAILLE];
  int * t = tab;
  int i = 0;
  for(i=0;i<TAILLE;++i)
    {
      printf("tab[%d]= ? ",i);
      scanf("%d",t+i);
    }
  int max, min;
  max = min = *t;

  for(i=0;i<TAILLE;++i)
    {
      max = (max < *(t+i)) ? *(t+i) : max;
      min = (min > *(t+i)) ? *(t+i) : min; 
    }

  printf("min = %d ,max = %d\n",min,max);

  return 0;
}
