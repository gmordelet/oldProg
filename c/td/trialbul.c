//trialbul.c

#include<stdio.h>

void echangevaleur(int * a, int * b) {
	if (*b>*a) {
		*a+=*b;
		*b=*a-*b;
		*a=*a-*b;
		};
	}

void test(int * tableau, int taille) {
	int i,x,*t;
	t=tableau;
	for(x=0;x<taille;x++){
		for(i=0;i<taille-i;i++) {
			echangevaleur(t+i,t+i+1);
			};
	};
}	

int main () {

  int taille;
  printf("taille du tableau = ?");scanf("%d",&taille);

  int tableau[taille], * t;
  t=tableau;

  int i;
  for(i=0;i<taille;i++)
    {printf("tableau[%d] = ? ",i);scanf("%d",&tableau[i]);}

  test(t, taille);
  for(i=0;i<taille;i++){
    printf("valeur de tableau[%d] = %d \n",i,tableau[i]);
  }
  return(0);
}
