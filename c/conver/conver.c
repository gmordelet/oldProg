//conver.c

#include"headers.h"

int power(int n, int p)
{
  int n1 = 1;
  while(p>0)
    {
      n1 *= n;
      --p;
    }
  return n1;
}

int big_power(int n, int b)
{
  int x=0, p = 0;
  while(p<=n)
    {
      x = power(b,p);
      if(x>n) return (p-1);
      ++p;
    }
}

void print_base2(int n, int base)
{
  int i = big_power(n,base);
  while(i>=0)
    {
      printf("%c",int_to_char(n/power(base,i)));
      n-=(n/power(base,i))*power(base,i);
      --i;
    }
}

int char_to_int(char c)
{
  if(c>='0' && c<='9')
    {
      return c-48;
    }
  return c-55;
}

char int_to_char(int n)
{
  if(n<10) return n + 48;
  return n + 55;
}

void read(char string[], int int_array[])
{
  int i = 0;
  while(string[i] != 0)
    {
      int_array[i] = string[i]-48;
      ++i;
    }
}

int array_to_int(char tab[],int base)
{
  int i,p,x;
  i=p=x=0;
  while(tab[i] != 0)
    {
      x *= base;
      x += char_to_int(tab[i]);
      ++i;
      ++p;
    }
  return x;
}

int checking(char input[], int base)
{
  int i=0;
  while(input[i]!=0)
    {
      if(char_to_int(input[i])>=base)
	return 0;
      ++i;
    }
  return 1;
}
