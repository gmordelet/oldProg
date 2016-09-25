#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  char buff1[200], buff2[200], c;
  int i;

  if(argc != 2)
    return -1;

  fp = fopen(argv[1], "r");
  if(fp == NULL)
    return;

  c = 0;
  while(c != EOF)
    {
      strcpy(buff1, "touch '");
      i = 0;
      while((c = fgetc(fp)) != '\n' && c != EOF)
	buff2[i++] = c;
      if(!i)
	continue;
      buff2[i] = '\0';
      strcat(buff1, buff2);
      strcat(buff1, "'");
      printf("%s\n", buff1);
      system(buff1);
    }

  return 0;
}
