#include<stdio.h>
#include<string.h>

#define MAXL 200

char buff[MAXL];

FILE *fp;

void GetWord();
void AddName();
void RemoveName();
void NameListed();
int find(char *);
void PrintList();

int main()
{
  fp = fopen("list", "r+");
  if(fp == NULL)
    {
      return 0;
    }

  GetWord();
  if(!strcmp("add", buff))
    {
      GetWord();
      AddName();
      return 0;
    }
  if(!strcmp("remove", buff))
    {
      GetWord();
      RemoveName();
      return 0;
    }
  if(!strcmp("print", buff))
    {
      PrintList();
      printf("\n");
      return 0;
    }
  NameListed();
  return 0;
}

void GetWord()
{
  int i, c;
  i = 0;
  while((c = getchar()) != '\n')
    buff[i++] = c;
  buff[i] = 0;
}

void AddName()
{
  int c, i;
  char _buff[MAXL];
  fseek(fp, 0, 0);  

  i = 0;
  c = fgetc(fp);
  if(c != EOF)
    {
      fseek(fp, 0, 0);  
      while(1)
      {
	c = fgetc(fp);
	if(c == '\n' || c == EOF)
	  {
	    _buff[i] = 0;
	    i = 0;
	    if(!strcmp(_buff, buff))
	      {
		printf("Nom deja depose\n");
		return;
	      }
	    if(c == EOF)
	      {
		break;
	      }
	    continue;
	  }
	_buff[i++] = c;
      }
      putc('\n', fp);
    }  
  i = 0;
  while(buff[i] != 0)
    {
      fputc(buff[i++], fp);
    }
}

void RemoveName()
{
  int c, i, find;
  char _buff[MAXL];
  FILE *_fp = fopen("list2", "w");
  i = find = 0;
  while(1)
    {
      c = fgetc(fp);
      if(c == '\n' || c == EOF)
	{
	  _buff[i] = '\0';
	  if(strcmp(_buff, buff))
	    {
	      if(c == '\n')
		{
 		  _buff[i] = c;
		  _buff[++i] = '\0';
		}
	      fputs(_buff, _fp);
	    }
	  else
	    {
	      find = 1;
	    }
	  if(c == EOF)
	    {	    
	      break;
	    }
	  i = 0;
	  continue;
	}
      _buff[i++] = c;
    }
  if(!find)
    {
      printf("Le nom n a pas ete trouve\n");
    }

  remove("list");
  rename("list2", "list");
}

void NameListed()
{
  int c, i;
  char _buff[MAXL];
  i = 0;
  printf("%s -> ", buff);
  while(1)
    {
      if((c = fgetc(fp)) == '\n' || c == EOF)      
	{
	  _buff[i] = '\0';
	  if(find(_buff))
	    {
	      printf("%s ", _buff);
	    }
	  if(c == EOF)
	    {
	      break;
	    }
	  i = 0;
	}
      else
	{
	  _buff[i++] = c;
	}
    }
  printf("\n");
}

int find(char *_buff)
{
  int l1, l2, i, j;
  l1 = strlen(buff);
  l2 = strlen(_buff);
  i = 0;
  while(l1 + i <= l2)
    {
      j = 0;
      while(buff[j] == _buff[i + j] && _buff[i + j] != '\0')
	{
	  ++j;
	}
      if(buff[j] == '\0')
	{
	  return 1;
	}
      ++i;
    }
  return 0;
}

void PrintList()
{
  int c;
  while((c = fgetc(fp)) != EOF)
    {
      putchar(c);
    }
}
