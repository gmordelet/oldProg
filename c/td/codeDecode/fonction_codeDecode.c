//fonction_codeDecode.c

#include"define.h"

int codeN(int n, int a){
  return (n*a)%NBL;
}

int retour_lettre(char c){
  int x=c-97;
  if (x<NBL&&x>=0) return x;
  return -1;
}

char retour_nombre(int a){
  return a+97;
}

char codeChar(char c, int a){
  if (retour_lettre(c)==-1) return c;
  return retour_nombre(codeN(retour_lettre(c),a));
}

char decodeChar(char c, int a){
  int i;
  for(i=0;i<NBL;i++){
    if (c==codeChar(retour_nombre(i),a)) return retour_nombre(i);
  }
}

void codeChaine(char *c1, char *c2, int a){
  int i;
  for(i=0;i<TAILLE;i++){
    c2[i]=codeChar(c1[i],a);
  }
}

int essai(int a,int u){
  int i, s=0;
  for (i=0;i<NBL;i++){
    if (codeChar(codeChar(retour_nombre(i),a),u)!=retour_nombre(i)){
      s+=1;
    } 
  }
  if (s==0) return 1;
  return 0;
}

int cleInverse(int a, int *b){
  int i;
  for(i=0;i<NBL;i++){
    if (essai(CLE,i))
    *b=i;
    return 1;
  }
  return 0;
}
