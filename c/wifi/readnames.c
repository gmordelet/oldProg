#include"headers.h"
#include"_headers.h"

void ReadNames(t_name *namesArray)
{
  int c, i, j, jump;
  FILE *fp = fopen("log", "r");
  unsigned char buff[MAX_NAME];
  unsigned long pos;

  i = j = pos = 0;
  
  while((c = fgetc(fp)) != EOF)
    {
      ++pos;
      buff[j++] = c;
      if(c == 0)
	{
	  j = 0;
	  jump = ReadNum(fp);
	  pos += 8;
	  namesArray[i].count = jump;
	  namesArray[i].name = AllocName(buff);
	  namesArray[i].pos = pos;
	  pos += 8 * jump;
	  ++i;
	  fseek(fp, jump * 8, SEEK_CUR);
	}
    }
  fclose(fp);
}

char *AllocName(char *name)
{
  char *temp = malloc(strlen(name) + 1);
  strcpy(temp, name);
  return temp;
}

void PrintDates(t_name *namesArray)
{
  int i;
  FILE *fp = fopen("log", "r");
  unsigned long time;

  while((*namesArray).name != NULL)
    {
      fseek(fp, (*namesArray).pos, SEEK_SET);
      printf("[%d] %s > count = %ld\n", i, (*namesArray).name, (*namesArray).count);
      ++namesArray;
      ++i;
    }
  fclose(fp);
}

void PrintDate(t_name *namesArray, int choice)
{
  FILE *fp;
  unsigned long jump;
  time_t _time;

  if(choice > MAX_ARR || namesArray[choice].name == NULL)
    return;

  fp = fopen("log", "r");
  fseek(fp, namesArray[choice].pos, SEEK_SET);
  printf("%s\n", namesArray[choice].name);
  for(jump = namesArray[choice].count; jump > 0; --jump)
    {
      _time = ReadNum(fp);
      printf(" %s", ctime(&_time));
    }

  fclose(fp);
}


