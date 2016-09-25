#ifndef BASH_H
#define BASH_H

#include"subjects.h"

void BashMenu(int, int, SubjectNode *);
unsigned int GetWords(char *, int);
unsigned int GetLine(char *, int);
Subject GetSubjectBash(int, SubjectNode *);


#endif
