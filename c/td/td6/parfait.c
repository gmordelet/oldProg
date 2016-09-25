//parfait.c

#include<stdio.h>

int main()
{
  int i=0,j,x;
  while(i<=10000)
    {
      x=0;
      j=1;
      while(j<=i/2)
	{ 
	  if(i%j==0)x+=j;
	  ++j;
	 }
      if(x==i)printf("%d parfait\n",x);
      ++i;
    }

  return 0;
}
