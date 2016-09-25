#include"headers.h"

#define MAXNAME 200

int test = 1;

int main(int argc, char *argv[])
{
  if(test)
    {
      char name[MAXNAME] = "salut1";
      UpName(name);
      return 0;
    }

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
