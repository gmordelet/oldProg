//codeDecode.c

#include<stdio.h>
#include<string.h>

#define NBL 26
#define TAILLE 50
#define CLE 19

int codeN(int n, int a);
char codeChar(char c, int a);
int retour_lettre(char c);
char retour_nombre(int a);
char codeChar(char c, int a);
void codeChaine(char *c1, char *c2, int a);
char decodeChar(char c, int a);
int essai(int a,int u);

int main(){
  printf("CLE = %d\n",CLE);
  
  char ch[TAILLE]="chaine de test", cr[TAILLE];
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
  printf("cle inverse de %d = %d\n",CLE,cleInverse(CLE,&b));


  return(0);
}

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
