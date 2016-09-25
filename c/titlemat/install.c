#include<stdio.h>

int main()
{
  FILE *fp;
  
  if((fp = fopen("/bin/titlemat", "r")) != NULL)
    {
      system("sudo rm -i /bin/titlemat");
    }
  
  system("sudo cp -v titlemat -t /bin/");

  return 0;
}
