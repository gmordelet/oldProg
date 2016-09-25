//sommecube.c

#include<stdio.h>

int cube(int a)
{
  return a*a*a;
}

int chiffre(int a)
{
  int x=0,b=a;
  for(;;)
    {
      x+=cube(b%10);
      b-=(b%10);
      b/=10;
      if(b==0)break;
    }
  if(x==a)return 1;
  return 0;
}

int main()
{
  int i=0;
  while(i<=10000)
    {
      if (chiffre(i)) printf("%d\n",i);
      ++i;
    }
  return 0;
}
