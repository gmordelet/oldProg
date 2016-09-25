//compteSupprimeA.c

#include<stdio.h>
#include<string.h>

#define TAILLE 50

int main(){
  printf("\n");
  static char ch[]="voila une chaine de caracteres";
  char *adresse_a[strlen(ch)];
  int position[strlen(ch)];
  int i=0,x=0;
  printf("%s\n",ch);  
  while(i<strlen(ch)){
    adresse_a[i]=NULL;
    ++i;
  }
  i=0;
  while(i<strlen(ch)){
    if (ch[i]=='a'){
      adresse_a[x]= &ch[i];
      ++x;
    }
    ++i;
  }
  i=0;
  while(i<x){
    *(adresse_a[i])=' ';
    ++i;
  }
  printf("%s\n",ch);
  i=0;
    while(i<strlen(ch)){
      if(ch[(int)strlen(ch)-i-1]!=' ') printf("%c",ch[(int)strlen(ch)-i-1]-32);
      else printf(" ");
      i++;
}
  printf("\n");
  printf("\n");
  return 0;
}
