#include"headers.h"

#define MAXNAME 200

int main(int argc, char *argv[])
{
  /*
  unsigned long bytesArr[0xFF + 1], total;
  unsigned char *codesArr[0xFF + 1];
  char *nameWrite, *nameWriteDecomp;
  int fdRead, fdWrite;
  node *root;

  if(argc != 2)
    {
      printf("Erreur : Doit avoir un argument\n");
      exit(EXIT_FAILURE);
    }
  if((fdRead = open(argv[1], O_RDONLY)) == -1)
    {
      printf("Erreur ouverture '%s' : %s\n", argv[1], strerror(errno));
      exit(EXIT_FAILURE);
    }
  nameWrite = malloc(sizeof(char) * (strlen(argv[1]) + 5));
  strcpy(nameWrite, argv[1]);
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

  if((fdRead = open(nameWrite, O_RDONLY)) == -1)
    {
      printf("Erreur ouverture '%s' : %s\n", nameWrite, strerror(errno));
      exit(EXIT_FAILURE);
    }
  nameWriteDecomp = malloc(sizeof(char) * (strlen(argv[1]) + 6));
  strcpy(nameWriteDecomp, argv[1]);
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
  */

  char choice;

  if(argc != 2)
    {
      printf("Erreur : Doit avoir un argument\n");
      exit(EXIT_FAILURE);
    }

  printf("(C)ompress ? (D)ecompress ? ");
  choice = getchar();

  switch(choice)
    {
    case'C':
    case'c':
      compress(argv[1]);
      break;
    case'd':
    case'D':
      decompress(argv[1]);
      break;
    default:
      break;
    }

  exit(EXIT_SUCCESS);
}
