//emot.c

#include<stdio.h>
#include<string.h>

#define TAILLE 100

int main(){
  printf("\n");
  char tab[TAILLE]={0};
  printf("chaine à tester ? ");
  scanf("%[^\n]",tab);
  printf("%s\n",tab);
  int i,x,xe=0;
  for(i=0;i<30;i++){
    if (tab[i]=='e')xe++;
  }
  printf("la chaine contient %d 'e'\n",xe);
  x=0;
  for(i=1;i<TAILLE;i++){
    if(tab[i]==' '||tab[i]==0){
      if(tab[i-1]!=0&&tab[i-1]!=' ')x++;
      }
  }
  printf("la chaine contient %d mot(s)\n",xe);
  x=0;
  for(i=0;i<TAILLE;i++){
    if(tab[i]!=0&&tab[i]!=' ')x++;
  }
  printf("la chaine contient %d caractere(s) imprimables\n",x);
  printf("pourcentages de 'e' = %d pourcents",xe*100/((int)strlen(tab)));
 printf("\n");
}
