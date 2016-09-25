//fonction.c

#include<stdio.h>

int dePetEaN(int p, int e){
  int i,xp=p;
    
  if(e==0)return 1;
  for(i=2;i<=e;i++){
    p*=xp;
  }
  return p;
}

void procedure1(){
  int p,e;
  printf("procedure1: lire un nombre p et un exposant e, afficher  p puissance e\n");
  printf("p = ? ");
  scanf("%d",&p);
  printf("e = ? ");
  scanf("%d",&e);
  printf("%d^%d = %d\n",p,e,dePetEaN(p,e));
}

int deNetPaE(int n, int p){
  int e=1;
  while((n%dePetEaN(p,e))==0) e++;
  return e-1;
}

void procedure2(){
  int n,p;
  printf("procedure2: lire un nombre n et un diviseur p, afficher l'exposant.\n");
  printf("n = ? ");
  scanf("%d",&n);
  printf("p = ? ");
  scanf("%d",&p);
  printf("%d est divisible %d fois par %d\n",n,deNetPaE(n,p),p);
}

void lireDTC(int *d, int *t, int *c){
  printf("d = ? ");scanf("%d",d);
  printf("t = ? ");scanf("%d",t);
  printf("c = ? ");scanf("%d",c);
}

int deDTCaN(int d,int t,int c){
  return dePetEaN(2,d)*dePetEaN(3,t)*dePetEaN(5,c);
}

void afficheDTC(int d,int t,int c){
  printf("2^%d 3^%d 5^%d",d,t,c);
}

void procedure3(){
  int d,t,c;
  printf("procedure3: lire 3 exposants d, t, c et afficher le nombre correspondant.\n");
  lireDTC(&d,&t,&c);
  afficheDTC(d,t,c);
  printf("= %d\n",deDTCaN(d,t,c));
}

void DeNaDTC(int *n, int *d, int *t, int *c){
  *d=deNetPaE(*n,2);  
  *t=deNetPaE(*n,3);
  *c=deNetPaE(*n,5);
}  

int  estUnDTC(int n){
  int d,t,c,m;
  DeNaDTC(&n,&d,&t,&c);
  m=deDTCaN(d,t,c);
  if (m==n) return 1;
  return 0;
}

void procedure4(){
  int n,d,t,c,m;
  printf("procedure4: test si un nombre est de la forme DTC\n");
  printf("n ? ");scanf("%d",&n);
  if(estUnDTC(n)){
      printf("%d est de la forme DTC\n",n);
      DeNaDTC(&n,&d,&t,&c);
      afficheDTC(d,t,c);
      printf(" = %d\n",n);

    }
  else{
      printf("%d n'est pas de la forme DTC\n",n);
      DeNaDTC(&n,&d,&t,&c);
      m = n/deDTCaN(d,t,c);
      afficheDTC(d,t,c);
      printf(" %d  = %d\n",m,n);
  }
}

void procedure5(){
  int i;
  printf("procedure5: affichage des nombres DTC compris entre 1 et 50\n");
  for(i=1;i<=50;i++){
    if (estUnDTC(i)) printf("%d ",i);
  }
  printf("\n");
}

int min(int a, int b){
  if(a<b)return a;
  return b;
}

int max(int a, int b){
  if(a<b)return b;
  return a;
}

int pgcdDTC(int a, int b){
  int da,ta,ca,db,tb,cb;
  DeNaDTC(&a,&da,&ta,&ca);
  DeNaDTC(&b,&db,&tb,&cb);
  return deDTCaN(min(da,db),min(ta,tb),min(ca,cb));
}

int ppcmDTC(int a, int b){
  int da,ta,ca,db,tb,cb;
  DeNaDTC(&a,&da,&ta,&ca);
  DeNaDTC(&b,&db,&tb,&cb);
  return deDTCaN(max(da,db),max(ta,tb),max(ca,cb));
}

void procedure6(){
  int n,m;
  printf("procedure6: calcul du pgcd et du ppcm de 2 nombres m et n de forme DTC\n");
  printf("m ? ");scanf("%d",&m);
  printf("n ? ");scanf("%d",&n);
  if(!(estUnDTC(m)&&estUnDTC(n))){
    printf("C'est pas des DTC ducon\n");
    return;
 }
  printf("pgcd(%d,%d) = %d\n",m,n,pgcdDTC(m,n));
  printf("ppcm(%d,%d) = %d\n",m,n,ppcmDTC(m,n));
  
}
