#ifndef SUBJECTS_H
#define SUBJECTS_H

typedef struct Subject Subject;
struct Subject{
  int num;
  char *name;
  struct NumNode *numnode;
};

typedef struct SubjectNode SubjectNode;
struct SubjectNode{
  Subject *subject;
  SubjectNode *next;
};

typedef struct NumNode NumNode;
struct NumNode{
  unsigned int val;
  NumNode *next;
};

#define BUFFSIZE 2000
#define MAXLEN 1000

int NameIsInList(SubjectNode *, char *);
void NumToBytes(unsigned int, unsigned char *);
void AddSubjectFd(int, Subject);
void AddNumNode(NumNode **, unsigned int);
unsigned int TwoBytesToNum(unsigned char, unsigned char);
Subject *NextSubjectFd(int, int);
void FreeNumNodeList(NumNode *);
void FreeSubject(Subject *);
Subject *NewSubject();
SubjectNode *ReadSubjectsFd(int);
void AddSubjectNode(SubjectNode **, Subject *);
void PrintSubject(Subject);
void PrintSubjectNodeList(SubjectNode *);
void RemoveSubjectFd(int *, SubjectNode **, int);
void RemoveSubjectNode(SubjectNode **, int);

#endif
