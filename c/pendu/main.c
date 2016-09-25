//pendu.c

#include"lib.h"

int main(){
  printf("\n");
  int debut=1;
  int coups=15;
  int fin=0;
  do{
    printf("Il vous reste %d coup(s) à jouer.\n",coups);
    tour_pendu(&debut, coups, &fin);
        --coups;
  }while(!fin);
  printf("fin de partie.\n");
  printf("\n");
  return 0;
}
