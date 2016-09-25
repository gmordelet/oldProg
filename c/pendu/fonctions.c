//fonctions.c

#include"lib.h"


char retour_clavier()
{
  char clavier, fake;
  scanf("%c",&clavier);
  do{
    scanf("%c",&fake);
  }while(fake!='\n');
  if (clavier>=65&&clavier<=91) return clavier; 
  if (clavier>=97&&clavier<=123) return (clavier-32);
  return 0;
}

void initialisation(int *debut, char mot[TAILLE], char mot_cache[TAILLE])
{
  while(*debut){
    int i;
    rand_dico(mot);
    
    *debut=1;
    for(i=0;i<TAILLE;i++){
      mot_cache[i]='\0';
    }
    for(i=0;i<(int)strlen(mot);i++){
      mot_cache[i]='*';
    }
    *debut=0;  
  }
}

void tour_pendu(int *debut,int coups, int *fin)
{
  static char mot[TAILLE];
  static char mot_cache[TAILLE];
  char clavier;
  int i,x=0;
  if(!coups)
    {
      printf("Vous avez perdu. Le mot etait : %s\n",mot);
      *fin=1;
      return;
    }
  initialisation(debut, mot, mot_cache);
  printf("Mot à trouver : <%s>\n",mot_cache);
 mot_a_trouver:
  printf("Tapez une lettre : ");
  clavier = retour_clavier();
  if(!clavier){
    printf("Caractere incorrecte\n");
    goto mot_a_trouver;
  }
  for(i=0;i<(int)strlen(mot);i++){
    if (mot[i]==clavier)mot_cache[i]=clavier;
  }
  for(i=0;i<(int)strlen(mot);i++){
    if(mot_cache[i]=='*')x++;
  }
  if(x==0){
    printf("%s\n",mot_cache);
    printf("Vous avez gagne\n");
    *fin=1;
  }
}




