//majuscules.c

#include<stdio.h>

#define TAILLE 100

int main(){
  printf("\n");
  char tab[TAILLE]={0};
  int i;
  printf("chaine à tester ? ");
  scanf("%[^\n]",tab);
  for(i=0;i<TAILLE;i++){
    if(tab[i]>=97&&tab[i]<=123)tab[i]-=32;
  }
  printf("%s\n",tab);
  printf("\n");
}

