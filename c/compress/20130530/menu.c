#include"headers.h"

void compress(char *name)
{
  unsigned long bytesArr[0xFF + 1], total;
  unsigned char *codesArr[0xFF + 1];
  char *nameWrite;
  int fdRead, fdWrite;

  if((fdRead = open(name, O_RDONLY)) == -1)
    {
      printf("Erreur ouverture '%s' : %s\n", name, strerror(errno));
      exit(EXIT_FAILURE);
    }
  nameWrite = malloc(sizeof(char) * (strlen(name) + 5));
  strcpy(nameWrite, name);
  strcat(nameWrite, "COMP");

  if((fdWrite = creat(nameWrite, S_IRWXU)) == -1)
    {
      printf("Erreur creation '%s' : %s\n", nameWrite, strerror(errno));
      exit(EXIT_FAILURE);
    }
  InitBytesArr(bytesArr);
  ReadBytes(fdRead, bytesArr);
  WriteBytesArr(fdWrite, bytesArr);
  MakeCodeArr(bytesArr, codesArr);
  WriteComp(fdRead, fdWrite, codesArr);
  close(fdRead);
  close(fdWrite);
}

void decompress(char *name)
{
  unsigned long bytesArr[0xFF + 1], total;
  unsigned char *codesArr[0xFF + 1];
  char *nameWriteDecomp;
  int fdRead, fdWrite;
  node *root;

  if((fdRead = open(name, O_RDONLY)) == -1)
    {
      printf("Erreur ouverture '%s' : %s\n", name, strerror(errno));
      exit(EXIT_FAILURE);
    }
  nameWriteDecomp = malloc(sizeof(char) * (strlen(name) + 6));
  strcpy(nameWriteDecomp, name);
  strcat(nameWriteDecomp, "DECOMP");
  if((fdWrite = creat(nameWriteDecomp, S_IRWXU)) == -1)
    {
      printf("Erreur creation '%s' : %s\n", nameWriteDecomp, strerror(errno));
      exit(EXIT_FAILURE);
    }

  ReadBytesDecomp(fdRead, bytesArr, &total);
  InitNodeArr(bytesArr);
  root = MakeTree();
  PrintDecomp(root, total, fdRead, fdWrite);
  FreeTree(root);
  close(fdRead);
  close(fdWrite);
}
