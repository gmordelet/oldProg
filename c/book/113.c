#include<stdio.h>
#include<string.h>

#define MAX 10
#define IN 1
#define OUT 0

void print_tab(int *tab)
{
  int i = 0;
  while(i<MAX)
    {
      printf("tab[%d] = %d\n",i,tab[i]);
      ++i;
    }
}

int main()
{
  int i, c, inword, max_length;
  int length[MAX];
  i = c = 0;
  memset(length,0,MAX*(sizeof(int)));
  inword = IN;

  while((c = getchar()) != '\n')
    {
      if((c != ' ') && (inword == OUT))
	{
	  ++i;
	  inword = IN;
	}
      if((c != ' ') && (inword == IN))
	{
	  ++length[i];
	}
      if(c == ' ')
	{
	  inword = OUT;
	}
    }
  i = 0;
  max_length = -1;
  while(max_length != 0)
    {
      i = 0;
      max_length = -1;
      while(i<MAX)
	{
	  max_length = (length[i]>=max_length) ? length[i] : max_length;
	  ++i;
	}
    
      i = 0;
      while(i<MAX)
	{
	  if(max_length == 0)
	    break;
	  if(length[i]==max_length)
	    {
	      printf("X ");
	      --length[i];
	    }
	  else 
	    printf("  ");
	  ++i;
	}
      printf("\n");
    }


  return 0;
}
