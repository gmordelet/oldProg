#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

#include"subjects.h"


int main(int argc, char **argv)
{
  int fdData, fdSubjects;
  char dataName[] = "data";
  char subjectsName[] = "subjects";
  SubjectNode *root;

  if((fdData = open(dataName, O_RDWR)) == -1)
    {
      fprintf(stderr, "Création de '%s'\n", dataName);
      if((fdData = creat(dataName, S_IRWXU)) == -1)
	{
	  fprintf(stderr, "Impossible de créer '%s' %s\n", dataName, strerror(errno));
	  exit(EXIT_FAILURE);
	}
      close(fdData);
      fdData = open(dataName, O_RDWR);
    }

  if((fdSubjects = open(subjectsName, O_RDWR)) == -1)
    {
      fprintf(stderr, "Création de '%s'\n", subjectsName);
      if((fdSubjects = creat(subjectsName, S_IRWXU)) == -1)
	{
	  fprintf(stderr, "Impossible de créer '%s' %s\n", subjectsName, strerror(errno));
	  exit(EXIT_FAILURE);
	}
      close(fdSubjects);
      fdSubjects = open(subjectsName, O_RDWR);
    }

  root = ReadSubjectsFd(fdSubjects);
  //  PrintSubjectNodeList(root);

  BashMenu(fdData, fdSubjects, root);
  
  close(fdData);
  close(fdSubjects);

  exit(EXIT_SUCCESS);
}
