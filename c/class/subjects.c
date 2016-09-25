/*
  Structure fichier 'subjects' : 
  -Deux octets correspondant au numéro du sujet
  -Nom sujet, se termine par un zero
  -Suites de deux octets correspondant à quels sujets le sujet est un sous-genre, se termine par deux zeros
  Puis sujet suivant.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include<fcntl.h>
#include"subjects.h"


int CheckNumNode()
{

}

void AddNumNode(NumNode **root, unsigned int val)
{
  NumNode *p = *root;

  if(p == NULL)
    {
      *root = malloc(sizeof(NumNode));
      (*root)->next = NULL;
      (*root)->val = val;
      return;
    }

  while(p->next != NULL)
    p = p->next;

  p->next = malloc(sizeof(NumNode));
  p->next->next = NULL;
  p->next->val = val;
}

/*
  NameIsInList
  Retourne le numéro correspondant au sujet, 0 si il n'est pas dans 'subjects'
*/
int NameIsInList(SubjectNode *root, char *subjectName)
{
  while(root != NULL)
    {
      if(!strcmp(root->subject->name, subjectName))
	return root->subject->num;
      root = root->next;
    }

  return 0;  
}


/*
  NumToBytes
  Convertit un int en 2 cases d'un tableau
  Appelé par AddSubjectFd
*/
void NumToBytes(unsigned int num, unsigned char *numArr)
{
  numArr[0] = num >> 8;
  numArr[1] = ~(~0 << 8) & num;
}

/*
  AddSubject
  Ajoute un sujet dans un fichier lié à un fd
*/
void AddSubjectFd(int fdSubjects, Subject subjectSrc)
{
  unsigned char buff[BUFFSIZE];
  int i, j;
  NumNode *p = subjectSrc.numnode;
  Subject *subjectPtr;

  NumToBytes(subjectSrc.num, buff);

  for(i = 2, j = 0; (subjectSrc.name)[j] != '\0'; ++i, ++j)
    buff[i] = (subjectSrc.name)[j];
  buff[i++] = 0;

  while(p != NULL)
    {
      if((i + 4) == BUFFSIZE)
	{
	  fprintf(stderr, "Erreur %s() : Pas assez d'espace dans buff\n", __FUNCTION__);
	  exit(EXIT_FAILURE);
	}
      NumToBytes(p->val, buff + i);
      p = p->next;
      i += 2;
    }
  buff[i++] = 0;
  buff[i] = 0;

  subjectPtr = malloc(sizeof(Subject));
  *subjectPtr = subjectSrc;

  lseek(fdSubjects, 0, SEEK_END);

  write(fdSubjects, buff, i + 1);
}

/*
  TwoByteesToNum
  Convertit 2 bytes en un unsigned int
*/
unsigned int TwoBytesToNum(unsigned char b1, unsigned char b2)
{
  return b1 << 8 | b2;
}

Subject *NewSubject()
{
  Subject *subjectBuff = malloc(sizeof(Subject));

  subjectBuff->name = NULL;
  subjectBuff->numnode = NULL;
  subjectBuff->num = 0;

  return subjectBuff;
}

/*
  NextSubjectFd
  Renvoie un sujet du fichier lié à un fd à chaque appel
  begin = 1 pour reprendre le fd depuis le début
*/
Subject *NextSubjectFd(int fdSubject, int begin)
{
  int j, readName, readNum, readNumNode;
  unsigned int numNode;
  unsigned char buffName[MAXLEN], num1, num2, numNode1, numNode2;
  Subject *subjectBuff;
  static int i = 0;
  static int n = 0;
  static unsigned char buff[BUFFSIZE];

  subjectBuff = NewSubject();

  readNumNode = readName = j = 0;
  readNum = 1;

  if(begin == 1)
    {
      i = n = 0;
      lseek(fdSubject, 0, SEEK_SET);
    }

  while(1)
    {
      if(i == n)
	{
	  i = 0;
	  n = read(fdSubject, buff, BUFFSIZE);
	}

      if(!n)
	return NULL;
      
      if(n == -1)
	{
	  fprintf(stderr, "Erreur %s() : %s\n", __FUNCTION__, strerror(errno));
	  exit(EXIT_FAILURE);
	}

      while(i < n)
	{
	  if(readNum == 1)
	    {
	      num1 = buff[i++];
	      readNum = 2;
	      continue;
	    }

	  if(readNum == 2)
	    {
	      readNum = 0;
	      num2 = buff[i++];
	      subjectBuff->num = TwoBytesToNum(num1, num2);
	      readName = 1;
	      continue;
	    }

	  if(readName && buff[i])
	    {
	      buffName[j++] = buff[i++];
	      continue;
	    }

	  if(readName && !buff[i])
	    {
	      buffName[j] = '\0';
	      readName = 0;
	      subjectBuff->name = malloc(sizeof(char) * strlen(buffName) + 1);
	      strcpy(subjectBuff->name, buffName);
	      ++i;
	      readNumNode = 1;
	    }

	  if(readNumNode == 1)
	    {
	      numNode1 = buff[i++];
	      readNumNode = 2;
	      continue;
	    }
	  //readNumNode forcément égal à 2

	  numNode2 = buff[i++];
	  if(numNode = TwoBytesToNum(numNode1, numNode2))
	    {
	      AddNumNode(&(subjectBuff->numnode), numNode);
	      readNumNode = 1;
	      continue;
	    }

	  return subjectBuff;
	}
    }
}

void FreeNumNodeList(NumNode *root)
{
  NumNode *p1, *p2;

  p1 = root;

  if(root == NULL)
    return;

  while(p1->next != NULL)
    {
      p2 = p1->next;
      free(p1);
      p1 = p2;
    }
  free(p1);
}

void FreeSubject(Subject *subjectDest)
{
  if(subjectDest == NULL)
    {
      printf("Erreur %s() : subjectDest = NULL\n", __FUNCTION__);
      return;
    }
  free(subjectDest->name);
  FreeNumNodeList(subjectDest->numnode);
  free(subjectDest);
}

/*
  ReadSubjects
  Renvoie une liste de tous les sujets contenus dans un fichié lié à un fd
*/
SubjectNode *ReadSubjectsFd(int fdSubjects)
{
  SubjectNode *root, *p;
  Subject *subjectPtr;

  if((subjectPtr = NextSubjectFd(fdSubjects, 1)) == NULL)
    return NULL;

  root = malloc(sizeof(SubjectNode));
  p = root;
  p->subject = subjectPtr;

  while((subjectPtr = NextSubjectFd(fdSubjects, 0)) != NULL)
    {
      p->next = malloc(sizeof(SubjectNode));
      p->next->subject = subjectPtr;
      p = p->next;
    }

  p->next = NULL;

  return root;
}

void AddSubjectNode(SubjectNode **root, Subject *subjectSrc)
{
  SubjectNode *p;

  if(*root == NULL)
    {
      *root = malloc(sizeof(SubjectNode));
      (*root)->subject = subjectSrc;
      (*root)->next = NULL;
      return;
    }

  p = *root;

  while(p->next != NULL)
    p = p->next;

  p->next = malloc(sizeof(SubjectNode));
  p->next->next = NULL;
  p->next->subject = subjectSrc;
}

void PrintSubject(Subject subjectSrc)
{
  NumNode *p = subjectSrc.numnode;

  printf("'Num = %d, name = %s, sg de ", subjectSrc.num, subjectSrc.name);
  while(p != NULL)
    {
      printf("%d ", p->val);
      p = p->next;
    }
  printf("'\n");
}

void PrintSubjectNodeList(SubjectNode *root)
{
  printf("PrintSubjectNodeList--\n");
  while(root != NULL)
    {
      PrintSubject(*(root->subject));
      root = root->next;
    }
  printf("----------------------\n");
}

void RemoveSubjectNode(SubjectNode **root, int subjectNum)
{
  SubjectNode *p1, *p2, *p3;

  p1 = *root;
  if(p1 != NULL)
    if(p1->subject->num == subjectNum)
      {
	*root = p1->next;
	FreeSubject(p1->subject);
	free(p1);
	return;
      }

  while(p1->next != NULL)
    {
      p2 = p1;
      if(p1->next->subject->num == subjectNum)
	{
	  p3 = p1->next;
	  FreeSubject(p1->next->subject);
	  p2->next = p1->next->next;
	  free(p3);
	  return;
	}
      p1 = p2->next;
    }

  printf("Erreur %s() : Suject introuvavble\n", __FUNCTION__);
}

/*
  RemovSubjectFd
  Supprime un sujet dans un fichier lié à un file descriptor
  Modifie le fd pour lui donner la bonne valeur
  Crée un fichier subjectbackup
*/
void RemoveSubjectFd(int *fdSubjects, SubjectNode **root, int subjectNum)
{
  int fdTemp = creat("subjectstemp", S_IRWXU);
  SubjectNode *p = *root;

  if(fdTemp == -1)
    {
      printf("Erreur %s() : %s\n", __FUNCTION__, strerror(errno));
      exit(EXIT_FAILURE);
    }

  close(fdTemp);

  if((fdTemp = open("subjectstemp", O_RDWR)) == -1)
    {
      printf("Erreur %s() : %s\n", __FUNCTION__, strerror(errno));
      exit(EXIT_FAILURE);
    }

  close(fdSubjects);

  RemoveSubjectNode(root, subjectNum);
  
  while(p != NULL)
    {
      if(p->subject->num != subjectNum)
	  AddSubjectFd(fdTemp, *(p->subject));
      p = p->next;
    }

  close(*fdSubjects);
  *fdSubjects = fdTemp;

  unlink("subjectsbackup");
  rename("subjects", "subjectsbackup");
  rename("subjectstemp", "subjects");
}
