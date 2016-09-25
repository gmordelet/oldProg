//codeDecode.c

#include"fonction_codeDecode.h"



int main(){
  printf("\n");
  printf("CLE = %d\n",CLE);
  
  /* char ch[TAILLE]="chaine de test", cr[TAILLE];
  codeChaine(ch,cr,CLE);
  printf("chaine de test=<%s>, chaine de test code=<%s>\n\n",ch,cr);
  
  int i;
  char code[NBL];
  for(i=0;i<NBL;i++){
    code[i]=codeChar(retour_nombre(i),CLE);
    printf("code(%c)=%c\n",retour_nombre(i),codeChar(retour_nombre(i),CLE));
  }
  char decode[NBL];
  for(i=0;i<NBL;i++){
    decode[i]=decodeChar(retour_nombre(i),CLE);
    printf("decode(%c)=%c\n",retour_nombre(i),decodeChar(retour_nombre(i),CLE));
  }
  int b;
  printf("cle inverse de %d = %d\n",CLE,cleInverse(CLE,&b));*/
  char clavier[TAILLE], clavier_transcrit[TAILLE];
    printf("Chaine à transcrire ?");
    scanf("%[^\n]",clavier);
    codeChaine(clavier,clavier_transcrit,CLE);
    printf("%s\n",clavier_transcrit);
  printf("\n");

  return(0);
}
