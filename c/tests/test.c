#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int StringToNum(char *s)
{
  int n = 0;

  while(*s != 0)
      n = 10 * n + (*(s++) - '0');

  return n;
}

int main()
{
  int fd;
  char name[] = "test.ppm";
  int perms = 00700;
  char width[] = "800";
  char height[] = "800";
  char maxVal[] = "255";
  char *head;
  char color1 = 0xF5;
  char color2 = 0x52;
  char color3 = 0x7E;
  char *buff;
  int i, j, size, n, count, matrixSize, shift, shiftColor;

  if((fd = open(name, O_RDONLY)) != -1)
    unlink(name);

  fd = creat(name, perms);
  
  size = strlen(width) + strlen(height) + strlen(maxVal) + 7;
  head = malloc(size);
  sprintf(head, "P6 %s %s %s ", width, height, maxVal);

  size = StringToNum(width) * StringToNum(height) * 3 + strlen(head);
  printf("size = %d = %x\n", size, size);
  buff = (char *)malloc(size);

  i = 0;
  while(*head != 0)
    buff[i++] = *(head++);
  matrixSize = StringToNum(width) * StringToNum(height) * 3;
  j = 0;
  shift = 0;
  while(j < matrixSize)
    {
      if(!((j + StringToNum(width)) % StringToNum(width) - shift))
	{
	  shiftColor = StringToNum(width) / 10;
	  while(j < matrixSize && shiftColor--)
	    {
	      buff[i + j++] = color1;
	      buff[i + j++] = color2;
	      buff[i + j++] = color3;
	    }
	  ++shift;
	}
      else
	{
	  buff[i + j++] = 0xFF;
	  buff[i + j++] = 0xFF;
	  buff[i + j++] = 0xFF;
	}
}

  n = write(fd, buff, size);
  printf("n = %d = %x\n", n, n);
  close(fd);

  return 0;
}
