#include<stdio.h>

int main()
{
  int i, x0, y0, zZ;
  float x, y, z, k;

  x0 = 200;
  y0 = 300;
  zZ = -150;

  for(i = 300; i <= 400; ++i)
    {
      k = i / 300;
      x = k * x0;
      y = k * y0;
      z = zZ * (1 - k);
      printf("k = %f, x = %f; y = %f; z = %f\n", k, x, y, z);
    }

  return 0;
}
