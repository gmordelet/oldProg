#include<stdio.h>
#include"fonctions.h"

int inverser(int x, int p, int n)
{
  int t = ~(~0 << n) << (p - 1);
  
  return x ^ t;
}

int main()
{
  int x = 155;

  printf("%s\n", StringBinaryConversion(x));
  x = inverser(x, 2, 3);
  printf("%s\n", StringBinaryConversion(x));

  return 0;
}
