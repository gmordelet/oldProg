#include <stdio.h>
#include "fonctions.h"

int FixerBits(int x, int p, int n, int y)
{
  int t = (~0 << (p + n - 1)) | ~(~0 << (p - 1));

  return (x & t) | (y & ~t);
}

int main()
{
  int x = 300;
  int y = 489;

  FixerBits(x, 3, 5, y);

  return 0;
}
