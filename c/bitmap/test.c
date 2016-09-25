#include<stdio.h>
#include<stdlib.h>
#include"bitmap.h"
#include<unistd.h>
#include<fcntl.h>
#include<>

int main(int argc, char **argv)
{
  int fd;
  BitmapInfo bitmapInfo;

  if(argc != 2)
    {
      printf("Pas d'arguments\n");
      return -1;
    }

  fd = open(argv[1], O_RDONLY);
  if(BitmapGetInfo(fd, &bitmapInfo) == -1)
    {
      printf("Erreur BitmapGetInfo()\n");
      return -1;
    }
  BitmapPrintInfo(bitmapInfo);



  return 0;
}
