#include"getnames.h"

void InitArrName(char **names)
{
  int i;
  for(i = 0; i < MAX_NAME; ++i)
    names[i] = NULL;
}

int SeekName(FILE *fp, char *name)
{
  int c;
  while((c = getc(fp)) != EOF)
    {
      if(c == '"')
	{
	  if((c = getc(fp)) == '"')
	    {
	      return EOF;
	    }
	  ungetc(c, fp);
	  while((c = getc(fp)) != '"')
	    {
	      printf("%c", c);
	      *(name++) = c;
	    }
	  *name = 0;
	  printf("\n");
	  return 0;
	}
    }
  return EOF;
}

int CheckName(char *buff, char **names)
{
  int i;
  for(i = 0; names[i] != NULL && i < MAX_NAME; ++i)
    {
      if(!strcmp(names[i], buff))
	return 0;
    }
  return 1;
}

void AddName(char *buff, char **names)
{
  while(*names != NULL)
    *(++names);
  *names = malloc(strlen(buff));
  strcpy(*names, buff);
}
