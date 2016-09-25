#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>

typedef struct longStack longStack;
struct longStack{
  longStack *prev;
  long val;
};

#define BUFFFDSIZE 5000

int CompFd(int fd1, int fd2)
{
  int i;
  char buff1[BUFFFDSIZE], buff2[BUFFFDSIZE];
}

void PushLongStack(longStack **pile, long val)
{
  longStack *longStackTemp;

  longStackTemp = malloc(sizeof(longStack));
  if(longStackTemp == NULL)
    {
      fprintf(stderr, "Erreur PushLongStack : malloc NULL, %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }

  longStackTemp->prev = *pile;
  longStackTemp->val = val;
  *pile = longStackTemp;
}

long PopLongStack(longStack **pile)
{
  long val;
  longStack *p;

  if(*pile == NULL)
    {
      fprintf(stderr, "Erreur PopLongStack : pile = NULL\n");
      exit(EXIT_FAILURE);
    }

  val = (*pile)->val;
  p = (*pile)->prev;
  free(*pile);
  *pile = p;

  return val;
}

longStack *CopyLongPile(longStack *longPileSrc)
{
  longStack *pSrc, *pDest, *pReturn;

  if(longPileSrc == NULL)
    return NULL;

  pSrc = longPileSrc;
  pReturn = pDest = malloc(sizeof(longStack));
  while(pSrc->prev != NULL)
    {
      pDest->val = pSrc->val;
      pDest->prev = malloc(sizeof(longStack));
      pDest = pDest->prev;
      pSrc = pSrc->prev;
    }
  pDest->prev = NULL;
  pDest->val = pSrc->val;

  return pReturn;
}

void PrintLongPile(longStack *longPile)
{
  printf("PrintLongPile\n>>\n");
  if(longPile == NULL)
    {
      printf("Pile vide\n");
    }
  while(longPile != NULL)
    {
      printf("%ld\n", longPile->val);
      longPile = longPile->prev;
    }
  printf("<<\n");
}

void RemoveLastDir(char *path)
{
  path += strlen(path);
  while(*(--path) != '/')
    ;
  *path = '\0';
}

void FreeLongPile(longStack *pileComp)
{
  longStack *p1 = pileComp;
  longStack *p2;

  while(p1 != NULL)
    {
      p2 = p1->prev;
      free(p1);
      p1 = p2;
    }
}

int CompCount(char *path)
{
  DIR *dirBuff;
  struct dirent *direntBuff;
  struct stat statBuff;
  longStack *pile = NULL;
  long tellDirVal;
  int count = 0;
  char pathBuff[PATH_MAX + 1], pathNameBuff[PATH_MAX + 1];

  strcpy(pathBuff, path);

  dirBuff = opendir(pathBuff);
  if(dirBuff == NULL)
    {
      fprintf(stderr,"Erreur CompNumer : dirBuff = NULL, %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }

  PushLongStack(&pile, -2);
  while(1)
    {
      direntBuff = readdir(dirBuff);

      if(direntBuff == NULL)
	{
	  tellDirVal = PopLongStack(&pile);
	  closedir(dirBuff);
	  if(tellDirVal == -2)
	    break;
	  RemoveLastDir(pathBuff);
	  dirBuff = opendir(pathBuff);
	  seekdir(dirBuff, tellDirVal);
	  continue;
	}
      
      if(!strcmp("..", direntBuff->d_name) || !strcmp(".", direntBuff->d_name))
	continue;

      sprintf(pathNameBuff, "%s/%s", pathBuff, direntBuff->d_name);
      if((stat(pathNameBuff, &statBuff)) == -1)
	fprintf(stderr, "%s\n", strerror(errno));

      if(S_ISDIR(statBuff.st_mode))
	{
	  sprintf(pathBuff,"%s/%s", pathBuff, direntBuff->d_name);
	  PushLongStack(&pile, telldir(dirBuff));
	  dirBuff = opendir(pathBuff);
	  if(dirBuff == NULL)
	    {
	      fprintf(stderr, "Erreur CompCount : dirBuff = NULL, %s\n", strerror(errno));
	    }
	}
      else
	  ++count;
    }
  return count;
}

void Comp(char *pathNameComp, longStack *pileComp, long telldirComp)
{
  DIR *dirBuff;
  struct dirent *direntBuff;
  struct stat statBuff, statComp;
  long tellDirVal;
  char pathBuff[PATH_MAX + 1], pathNameBuff[PATH_MAX + 1];
  int fd1, fd2;

  stat(pathNameComp, &statComp);

  strcpy(pathBuff, pathNameComp);
  RemoveLastDir(pathBuff);

  dirBuff = opendir(pathBuff);
  if(dirBuff == NULL)
    {
      fprintf(stderr,"Erreur Comp : dirBuff = NULL, %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  
  seekdir(dirBuff, telldirComp);

  while(1)
    {
      direntBuff = readdir(dirBuff);

      if(direntBuff == NULL)
	{
	  tellDirVal = PopLongStack(&pileComp);
	  if(tellDirVal == -2)
	    break;
	  RemoveLastDir(pathBuff);
	  closedir(dirBuff);
	  dirBuff = opendir(pathBuff);
	  seekdir(dirBuff, tellDirVal);
	  continue;
	}

      if(!strcmp("..", direntBuff->d_name) || !strcmp(".", direntBuff->d_name))
	continue;

      sprintf(pathNameBuff, "%s/%s", pathBuff, direntBuff->d_name);
      if((stat(pathNameBuff, &statBuff)) == -1)
	fprintf(stderr, "%s\n", strerror(errno));

      if(S_ISDIR(statBuff.st_mode))
	{
	  sprintf(pathBuff,"%s/%s", pathBuff, direntBuff->d_name);
	  PushLongStack(&pileComp, telldir(dirBuff));
	  closedir(dirBuff);
	  dirBuff = opendir(pathBuff);
	  if(dirBuff == NULL)
	    {
	      fprintf(stderr, "Erreur Comp : dirBuff = NULL, %s\n", strerror(errno));
	    }
	}
      else
	{
	  if(statComp.st_size == statBuff.st_size)
	    {
	      fd1 = open(pathNameComp, O_RDONLY);
	      fd2 = open(pathNameBuff, O_RDONLY);
	      if(CompFd(fd1, fd2))
		printf("%s == %s\n", pathNameComp, pathNameBuff);
	    }
	}
    }
  FreeLongPile(pileComp);
}

void ListComp(char *path)
{
  DIR *dirBuff;
  struct dirent *direntBuff;
  struct stat statBuff;
  longStack *pile = NULL;
  longStack *pileComp;
  long tellDirVal;
  char pathBuff[PATH_MAX + 1], pathNameBuff[PATH_MAX + 1];

  strcpy(pathBuff, path);

  dirBuff = opendir(pathBuff);
  if(dirBuff == NULL)
    {
      fprintf(stderr,"Erreur ListComp : dirBuff = NULL, %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }

  PushLongStack(&pile, -2);
  while(1)
    {
      direntBuff = readdir(dirBuff);

      if(direntBuff == NULL)
	{
	  tellDirVal = PopLongStack(&pile);
	  closedir(dirBuff);
	  if(tellDirVal == -2)
	    break;
	  RemoveLastDir(pathBuff);
	  dirBuff = opendir(pathBuff);
	  seekdir(dirBuff, tellDirVal);
	  continue;
	}
      if(!strcmp("..", direntBuff->d_name) || !strcmp(".", direntBuff->d_name))
	continue;

      sprintf(pathNameBuff, "%s/%s", pathBuff, direntBuff->d_name);
      if((stat(pathNameBuff, &statBuff)) == -1)
	fprintf(stderr, "%s\n", strerror(errno));
      if(S_ISDIR(statBuff.st_mode))
	{
	  sprintf(pathBuff,"%s/%s", pathBuff, direntBuff->d_name);
	  PushLongStack(&pile, telldir(dirBuff));
	  closedir(dirBuff);
	  dirBuff = opendir(pathBuff);
	  if(dirBuff == NULL)
	    {
	      fprintf(stderr, "Erreur ListComp : dirBuff = NULL, %s\n", strerror(errno));
	    }
	}
      else
	{
	  pileComp = CopyLongPile(pile);
	  Comp(pathNameBuff, pileComp, telldir(dirBuff));
	}
    }
}

int main(int argc, char **argv)
{
  struct stat buffStat;
  int totalComp;

  if(stat(".", &buffStat) == -1)
    {
      printf("%s\n", strerror(errno));
      return -1;
    }

  totalComp = CompCount(".");
  printf("%d\n", totalComp);
  ListComp(".");

  return 0;
}
