#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLEN 100

int main(int argc, char *argv[])
{
  char buff[MAXLEN], name1[MAXLEN], name2[MAXLEN];
  int i = 0;

  if(argc != 3)
    {
      printf("Erreur : Arguments\n");
      exit(EXIT_FAILURE);
    }

  while(argv[1][i] != '.')
    name1[i++] = argv[1][i];
  name1[i] = 0;

  i = 0;

  while(argv[2][i] != '.')
      name2[i++] = argv[2][i];
  name2[i] = 0;

  strcpy(buff, "gcc ");
  strcat(buff, argv[1]);
  strcat(buff, " -o ");
  strcat(buff, name1);
  system(buff);

  strcpy(buff, "gcc ");
  strcat(buff, argv[2]);
  strcat(buff, " -o ");
  strcat(buff, name2);
  system(buff);

  strcpy(buff, "./comp ");
  strcat(buff, name1);
  strcat(buff, " ");
  strcat(buff, name2);

  system(buff);

  return 0;
}
