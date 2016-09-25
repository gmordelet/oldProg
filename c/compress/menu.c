#include"headers.h"

void compress(char *name)
{
  unsigned long bytesArr[0xFF + 1], fileSize, segmentSize, pos, lastSize;
  unsigned char *codeArr[0xFF + 1];
  char *nameWrite;
  int fdRead, fdWrite, div, i;
  node *root;

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

  div = 3;
  fileSize = FdSize(fdRead);
  segmentSize = fileSize / div;
  if(!segmentSize)
    {
      printf("Fichier trop petit\n");
      exit(EXIT_FAILURE);
    }

  printf("div = %d\nfileSize = %ld\nsegmentSize = %ld\n", div, fileSize, segmentSize);

  InitCodeArr(codeArr);
  for(i = 0; i < div - 1; ++i)
    {
      pos = i * segmentSize;
      FreeCodeArr(codeArr);
      InitBytesArr(bytesArr);    
      ReadBytes(fdRead, segmentSize, bytesArr);
      WriteBytesArr(fdWrite, bytesArr);
      root = MakeCodeArr(bytesArr, codeArr);
      lseek(fdRead, pos, SEEK_SET);
      WriteComp(fdRead, fdWrite, segmentSize, codeArr);
      FreeTree(root);
    }
  pos = (div - 1) * segmentSize;
  lastSize = segmentSize + (fileSize % segmentSize);
  InitBytesArr(bytesArr);    
  ReadBytes(fdRead, lastSize, bytesArr);
  WriteBytesArr(fdWrite, bytesArr);
  MakeCodeArr(bytesArr, codeArr);
  lseek(fdRead, pos, SEEK_SET);
  WriteComp(fdRead, fdWrite, lastSize, codeArr);

  close(fdRead);
  close(fdWrite);
}

void decompress(char *name)
{
  unsigned long bytesArr[0xFF + 1], total, pos;
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

  pos = 0;
  while(ReadBytesDecomp(fdRead, bytesArr, &total) != EOF)
    {
      pos += (0xFF + 1) * 8;
      InitNodeArr(bytesArr);
      root = MakeTree();
      lseek(fdRead, pos, SEEK_SET);
      PrintDecomp(root, total, fdRead, fdWrite, &pos);
      FreeTree(root);
      lseek(fdRead, ++pos, SEEK_SET);
    }

  close(fdRead);
  close(fdWrite);
}
