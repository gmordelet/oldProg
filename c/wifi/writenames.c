#include"headers.h"
#include"_headers.h"

void WriteNames(char **names)
{
  FILE *fp = fopen("log", "r");
  if(fp == NULL)
    {
      fp = fopen("log", "w");
    }

  while(*names != NULL)
    {  
      WriteName(*names++);
    }
  fclose(fp);
}

void WriteName(char *name)
{
  int c, i, written;
  FILE *fp_read, *fp_write;
  unsigned char buff[MAX_NAME + 1];
  unsigned long jump;

  printf("Ecriture de %s\n", name);

  fp_read = fopen("log", "r");
  fp_write = fopen("log_temp", "w");
  written = 0;
  i = 0;
  jump = 0;

  while((c = fgetc(fp_read)) != EOF)
    {
      buff[i++] = c;
      fputc(c, fp_write);
      if(c == 0)
	{
	  i = 0;
	  if(!strcmp(buff, name))
	    {
	      written = 1;
	      jump = ReadNum(fp_read);
	      WriteNum(fp_write, jump + 1);
	      while(jump-- > 0)
		{
		  WriteNum(fp_write, ReadNum(fp_read));
		}
	      WriteNum(fp_write, time(NULL));
	    }
	  else
	    {
	      WriteNum(fp_write, jump = ReadNum(fp_read));
	      while(jump-- > 0)
		{
		  WriteNum(fp_write, ReadNum(fp_read));
		}
	    }
	}
    }

  if(!written)
    {
      fputs(name, fp_write);
      fputc(0, fp_write);
      WriteNum(fp_write, 1);
      WriteNum(fp_write, time(NULL));
    }

  fflush(fp_write);
  remove("log");
  rename("log_temp", "log");
  fclose(fp_read);
  fclose(fp_write);
}

void WriteNum(FILE *fp, unsigned long num)
{
  int i;
  unsigned long  min;
  unsigned char temp;
  for(i = 0; i < 8; ++i)
    {
      min = 1ul << (7 - i) * 8;
      temp = num / min;
      fputc(temp, fp);
      num -= temp * min;
    }
  fflush(fp);
}

unsigned long ReadNum(FILE *fp)
{
  int i;
  unsigned long sum;
  for(i = 0, sum = 0; i < 8; ++i)
    {
      sum += ((unsigned char)fgetc(fp)) * (1ul << (7 - i) * 8);
    }
  return sum;
}

void _pause(int sec)
{
  int i;
  for(i = 1; i <= sec; ++i)
    {
      sleep(1);
      printf("\r%3d", sec - i);
      fflush(stdout);
    }
  printf("\r   \n");
}
