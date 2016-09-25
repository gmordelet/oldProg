#include"headers.h"

int main(int argc, char *argv[])
{
  unsigned long byteArr[0xFF + 1] = {0};
  unsigned char *codesArr[0xFF + 1];
  char *nameWrite;
  FILE *fpRead, *fpWrite;

  if(argc != 2)
    {
      printf("Erreur : Doit avoir un argument\n");
      exit(EXIT_FAILURE);
    }

  if((fpRead = fopen(argv[1], "r")) == NULL)
    {
      printf("Erreur : Ouverture %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }

  nameWrite = malloc(sizeof(char) * (strlen(argv[1]) + 5));
  strcpy(nameWrite, argv[1]);
  strcat(nameWrite, "COMP");
  fpWrite = fopen(nameWrite, "w");
  if(fpWrite == NULL)
    {
      printf("Erreur : Creation %s\n", nameWrite);
    }

  ReadBytes(argv[1], byteArr);
  WriteBytesArr(fpWrite, byteArr);
  MakeCodeArr(byteArr, codesArr);
  WriteComp(fpRead, fpWrite, codesArr);
  
  unsigned long byteArrDecomp[0xFF + 1] = {0};
  unsigned long total;
  char nameWriteDecomp[100];
  FILE *fpWriteDecomp;
  node *root;
  int i;

  fpRead = fopen(nameWrite, "r");
  strcpy(nameWriteDecomp, argv[1]);
  strcat(nameWriteDecomp, "DECOMP");
  fpWrite = fopen(nameWriteDecomp, "w");
  ReadBytesDecomp(fpRead, byteArr, &total);
  InitNodeArr(byteArr);
  root = MakeTree();
  PrintDecomp(root, total, fpRead, fpWrite);

  exit(EXIT_SUCCESS);
}
