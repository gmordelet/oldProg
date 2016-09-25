//main.c

#include"headers.h"

int in, out;

void UsageError();

int main(int argc, char *argv[])
{
  int ask = 0 | ASKB1 | ASKB2;
  int c;

  while(--argc > 0 && (*++argv)[0] == '-')
    {
      c = *++argv[0];
      switch (c)
	{
	case 'i':
	  if(isdigit((*++argv)[0]))
	    {
	      in = atoi(*argv);
	      ask &= !ASKB1;
	      --argc;
	    }
	  else
	    {
	      UsageError();
	    }
	  break;
	case 'o':
	  if(isdigit((*++argv)[0]))
	    {
	      out = atoi(*argv);
	      ask &= !ASKB2;
	      --argc;
	    }
	  else
	    {
	      UsageError();
	    }
	  break;
	default:
	  UsageError();
	}
    }

  if(argc != 0)
    {
      UsageError();
    }

  menu(ask);
  return 0;
}

void UsageError()
{
  fprintf(stderr, "Usage : -i \"base in\" -o \"base out\"\n");
  exit(EXIT_FAILURE);
}
