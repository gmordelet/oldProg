#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"subjects.h"
#include"bash.h"

void BashMenu(int fdData, int fdSubjects, SubjectNode *root)
{
  Subject subjectBuff;
  int choice;

  printf("1 print, 2 add ");
  scanf("%d", &choice);

  switch(choice)
    {
    case 1 :
      PrintSubjectNodeList(root);
      break;
    case 2 :
      subjectBuff =  GetSubjectBash(fdSubjects, root);
      PrintSubject(subjectBuff);
      AddSubjectFd(fdSubjects, subjectBuff);
      break;
    default :
      printf("Mauvais choix\n");
      exit(EXIT_FAILURE);
    }


}

unsigned int GetLine(char *stringBuff, int lim)
{
  int c;
  unsigned int n = 0;

  while((c = getchar()) != EOF && c != '\n' && --lim > 0)
    {
      *(stringBuff++) = c;
      ++n;
    }
  stringBuff = '\0';

  return n;
}

unsigned int GetWords(char *stringBuff, int lim)
{
  int c;
  unsigned int n = 0;

  while((c = getchar()) != EOF && --lim > 0)
    {
      *(stringBuff++) = c;
      ++n;
    }
  stringBuff = '\0';

  return n;
}

Subject GetSubjectBash(int fdSubjects, SubjectNode *root)
{
  char stringBuff[MAXLEN], stringBuff1[MAXLEN];
  Subject subjectBuff = {0, NULL, NULL};
  int i, j, num;
  NumNode *NumNodeRoot = NULL;

  printf("Nom du sujet ? ");
  while(!GetLine(stringBuff, MAXLEN))
    ;

  if(NameIsInList(root, stringBuff))
    {
      printf("Sujet déjà dans la liste\n");
      return;
    }

  subjectBuff.name = malloc(sizeof(char) * strlen(stringBuff));
  strcpy(subjectBuff.name, stringBuff);

  //si pas de sujet, sort tout de suite de la boucle
  stringBuff[0] = '\0';
  printf("Sujet(s) parent(s) ? (Entrée entre chaque sujet, EOF pour finir la saisie) ");
  GetWords(stringBuff, MAXLEN);

  printf("\n");

  for(j = 0, i = 0; stringBuff[i] != '\0'; ++i)
    {
      if(stringBuff[i] == '\n')
	{
	  stringBuff1[j] = '\0';
	  j = 0;
	  if((num = NameIsInList(root, stringBuff1)))
	    AddNumNode(&(subjectBuff.numnode), num);
	  else
	    {
	      printf("'%s' n'est pas dans la liste\n", stringBuff1);
	      continue;
	    }
	}

      stringBuff1[j++] = stringBuff[i];
    }

  return subjectBuff;
}
