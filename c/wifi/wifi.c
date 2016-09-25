#include"headers.h"
#include"_headers.h"


int main()
{
  char buff[MAX_NAME], *names[MAX_NAME];
  FILE *fp;
  t_name namesArray[MAX_ARR];
  int choice;
  time_t _time;
  int i;

  printf("1 : Get 2 : Print ");
  scanf("%d", &choice);

  if(choice == 1)
    {
      while(1)
	{
	  _time = time(NULL);
	  printf("%s", ctime(&_time));
	  InitArrName(names);
	  system("sudo iwlist wlan0 scan >> temp");
	  fp = fopen("temp", "r");

	  while(SeekName(fp, buff) != EOF)
	    {
	      if(CheckName(buff, names))
		{
		  AddName(buff, names);
		}
	    }
	  WriteNames(names);  
	  remove("temp");
	  _pause(120);
	  fclose(fp);
	}
    }
  else if(choice == 2)
    {
      ReadNames(namesArray);
      PrintDates(namesArray);
      printf("Dates a lire ? ");
      scanf("%d", &choice);
      PrintDate(namesArray, choice);
    }

  return 0;
}

