#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<errno.h>

#define MAXLEN 200

int NameChanger(char *, char *, int);
int GetShowName(int);
int GetFile(char *, int);
void AvailableName();

char showName[MAXLEN];

int main(int argc, char *argv[])
{
  char fileName[MAXLEN];
  char buffNewName[MAXLEN];
  char availableName[MAXLEN];

  if(argc > 1)
    {
      printf("Nom de la serie ? ");
      GetShowName(MAXLEN);
      while(--argc >= 1)
	{
	  if(!NameChanger(*(argv++), buffNewName, MAXLEN))
	    {
	      AvailableName(buffNewName, availableName);
	      if(!rename(*argv, availableName))
		printf("%s -> %s\n", *argv, availableName);
	      else
		{
		  printf("Erreur %s -> ", *argv);
		  printf("%s\n", strerror(errno));
		}
	    }
	}
      return 0;      
    }

  printf("Nom de la serie ? ");
  GetShowName(MAXLEN);

  while(!GetFile(fileName, MAXLEN))
    {
      if(!NameChanger(fileName, buffNewName, MAXLEN))
	{
	  AvailableName(buffNewName, availableName);
	  if(!rename(fileName, availableName))
	    printf("%s -> %s\n", fileName, availableName);
	  else
	    {
	      printf("Erreur %s -> ", fileName);
	      printf("%s\n", strerror(errno));
	    }
	}
    }

  return 0;
}

/*
 NameChanger
 Recupere les numeros de saison et d episode dans originalName
 et les modifie selon newName
 Retourne -1 si les numeros nont pas pu etre changes, 0 sinon
 */
int NameChanger(char *originalName, char *newName, int lim)
{
  int i, j, gotten;
  char type[MAXLEN], season[MAXLEN], episode[MAXLEN];

  gotten = 0;

  for(i = 0; originalName[i]; ++i)
    {
      j = 0;

      if(isdigit(originalName[i]))
	{
	  while(isdigit(originalName[i]))
	      season[j++] = originalName[i++];

	  if(originalName[i] == 'x' || originalName[i] == 'X'
	     || originalName[i] == 'e' || originalName[i] == 'E')
	    {
	      if(isdigit(originalName[++i]))
		{
		  season[j] = '\0';
		  j = 0;

		  while(isdigit(originalName[i]))
		      episode[j++] = originalName[i++];

		  if(originalName[i] == '-')
		    if(isdigit(originalName[++i]))
		      {
			episode[j++] = '-';
			while(isdigit(originalName[i]))
			  episode[j++] = originalName[i++];
		      }
		  episode[j] = '\0';
		  gotten = 1;
		  break;
		}
	    }
	}
      if(!originalName[i])
	break;
    } 

  if(!gotten)
    {
      return -1;
    }

  if(strlen(episode) < 2)
    {
      episode[1] = episode[0];
      episode[0] = '0';
      episode[2] = 0;
    }

  if(strlen(season) < 2)
    {
      season[1] = season[0];
      season[0] = '0';
      season[2] = 0;
    }

  //recuperation du type du fichier
  i = strlen(originalName);
  j = 0;
  while(originalName[--i] != '.')
    ;
  while(type[j++] = originalName[i++])
    ;

  /*
  strcpy(newName, showName);
  strcat(newName, "-");
  strcat(newName, season);
  strcat(newName, "x");
  strcat(newName, episode);
  strcat(newName, type);
  */

  sprintf(newName, "%s-%sx%s%s", showName, season, episode, type);

  return 0;
}

int GetShowName(int lim)
{
  int i, c;

  i = 0;

  while((c = getchar()) != '\n' && c  != EOF)
      showName[i++] = c;

  showName[i] = 0;

  return i;
}

int GetFile(char *name, int lim)
{
  struct dirent *dp;
  static DIR *dirp = NULL;
  struct stat statbuf;

  if(dirp == NULL)
    {
      if((dirp = opendir(".")) == NULL)
	{
	  printf("Erreur opendir(\".\")\n");
	  exit(EXIT_FAILURE);
	}
    }

  dp = readdir(dirp);
  if(dp != NULL)
    {
      stat(dp->d_name, &statbuf);
    }

  //ne renvoie pas les dossiers, ni "." ni ".."
  while( dp != NULL
	 &&
	 (
             (statbuf.st_mode & S_IFMT) == S_IFDIR 
	  || strcmp(".", dp->d_name) == 0                                      
	  || strcmp("..", dp->d_name) == 0        
         )
       )
    {
      dp = readdir(dirp);
      if(dp != NULL)
	{
	  stat(dp->d_name, &statbuf);
	}
      
    }
  if(dp == NULL)
    {
      closedir(dirp);
      return -1;
    }

  strncpy(name, dp->d_name, lim - 1);

  name[strlen(dp->d_name)] = '\0';

  return 0;
}

void AvailableName(char *requestedName, char *availableName)
{
  FILE *fp;
  int i, j;
  char ext[MAXLEN]; //contient lextension du fichier

  if((fp = fopen(requestedName, "r")) == NULL)
    {
      strcpy(availableName, requestedName);
      return;
    }

  i = strlen(requestedName);
  while(requestedName[--i] != '.')
    ;
  strcpy(ext, requestedName + i);

  j = 1;
  while((fp = fopen(requestedName, "r")) != NULL)
    {
      requestedName[i] = '\0';
      sprintf(requestedName, "%s(%d)%s", requestedName, j, ext);
      ++j;
    }

  strcpy(availableName, requestedName);
}
