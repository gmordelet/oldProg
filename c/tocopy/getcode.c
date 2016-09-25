#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
  int c;
  FILE *fpi, *fpo;
  if(argc != 2)
    {
      printf("Erreur : Arguments\n");
      return 1;      
    }

  fpi = fopen(argv[1], "r");
  fpo = fopen("tocopyTab.c", "w");
  if(fpi == NULL || fpo == NULL)
    {
      printf("Erreur : Ouverture fichier");
      return 1;
    }

  fprintf(fpo, "#include<stdio.h>\nchar tab[] = {%d",c = fgetc(fpi));
  while((c = fgetc(fpi)) != EOF)
    fprintf(fpo, ", %d",c);
  fprintf(fpo, "};");

  fprintf(fpo, "int main()\
{\
  FILE *fp;\
  long int i = sizeof(tab) / sizeof(*tab) - 1;\
  int j = 0;\
\
  fp = fopen(\"tocopyFinal\", \"w\");\
  if(fp == NULL)\
    {\
      printf(\"Erreur : Acces tocopyFinal\");\
      return 1;\
    }\
  \
  while(i-- >= 0)\
      putc(tab[j++], fp);\
\
system(\"chmod u+x tocopyFinal\");\
  return 0;\
}\
");

  fclose(fpi);
  fclose(fpo);

  system("gcc tocopyTab.c -o extract");
  system("rm tocopyTab.c");

  return 0;
}
