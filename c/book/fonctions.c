#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>

int GetString(char s[], int lim)
{
  int c, size;
  
  size = 0;

  while((c = getchar()) != '\n' && c != EOF && --lim)
      s[size++] = c;
  s[size] = '\0';

  if(!lim)
    if(c != EOF && c != '\n')
      while((c = getchar()) != EOF && c != '\n')
	;
  
  return size;
}

int Power(int n, int p)
{
  int x = 1;

  while(p > 0)
    {
      x = x * n;
      --p;
    }
  
  return x;
}

int LargestTwoPower(int x)
{
  int i = 1;

  while(Power(2, i) <= x)
    ++i;

  return i;
}

char *StringBinaryConversion(int x)
{
  int i;
  int ltp = LargestTwoPower(x);
  char *s = malloc(sizeof(char) * ltp);

  for(i = 0; i < ltp; ++i)
    {
      s[ltp - 1 - i] = (x & 1) + '0';
      x >>= 1;
    }
  s[ltp] = '\0';

  return s;
}
