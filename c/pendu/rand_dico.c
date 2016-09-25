//rand_dico.h

#include"lib.h"

void rand_dico(char mot[TAILLE])
{
  srand(time(NULL));

  FILE *dico = NULL;

  dico=fopen("./dico","r");
  
  if(dico!=NULL)
    {
      char chaine[30];
      int x=0;
      for(;;)
	{
	  if(fgets(mot,TAILLE,dico)==NULL)break;
	  ++x;
	}
      fseek(dico,0,SEEK_SET);
      int i=1;
      while (i<rand()%x+1)
	{
	  for(;;){
	    if(fgetc(dico)=='\n')
	      {
		break;
	      }
	  } 
	  ++i;
	}
      fgets(mot,TAILLE,dico);
      mot[strlen(mot)-1]=0;
    }

  else printf("ouverture dico impossible\n");
 
  if(fclose(dico))printf("fermeture dico impossible\n");

}





