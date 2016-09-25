#include<stdio.h>

int main(int argc, char *argv[])
{
  char c1, c2;
  long int i;
  FILE *fp1, *fp2;

  if(argc != 3)
    {
      printf("Erreur : Arguments\n");
      return 1;
    }

  fp1 = fopen(argv[1], "r");
  fp2 = fopen(argv[2], "r");
  
  for(i = 0; (c1 = fgetc(fp1)) == (c2 = fgetc(fp2)) && c1 != EOF; ++i)
    ;
  if(c1 == c2 && c1 == EOF)
    {
      printf("Bits identiques\n");
      return 0;
    }
  
  printf("Bits differentes en %lx\n",i);

  fclose(fp1);
  fclose(fp2);

  return 0;  
}
