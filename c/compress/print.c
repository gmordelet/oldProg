#include"headers.h"

void UpName(char *name)
{
  int n, num;
  char buffNum[1];

  n = 1;
  num = 0;

  while(*name != '\0')
    {
      ++name;
    }
  --name;
  while(n >= 0 && isdigit(*name))
    {
      buffNum[n--] = *(name--);
    }
  printf("%c\n", buffNum[1]);
  if(!n)
    buffNum[0] = ' ';
  if(n != 1)
    {
      num = atoi(buffNum);
    }
  printf("num = %d\n", num);
  ++num;
}

int buffPrintCode[0xFF + 1];

void PrintCode(FILE *fp, node *root)
{
  int i, j, n;

  for(i = 0; i <= 0xFF; ++i)
    {
      fprintf(fp, "%d -> ", i);
      buffPrintCode[0] = 0;
      n = PrintCodeRec(i, 1, root->left);
      if(n > 0)
	{
	  j = 0;
	  while(n-- > 0)
	    {
	      fprintf(fp, "%d", buffPrintCode[j++]);
	    }
	  fprintf(fp, "\n");
	}

      buffPrintCode[0] = 1;
      n = PrintCodeRec(i, 1, root->right);
      if(n > 0)
	{
	  j = 0;
	  while(n-- > 0)
	    {
	      fprintf(fp, "%d", buffPrintCode[j++]);
	    }
	  fprintf(fp, "\n");
	}
    }
}

int PrintCodeRec(int c, int n, node *node)
{
  int nReturn;

  if(node->left == NULL)
    {
      if(node->c == c)
	{
	  return n;
	}
      return 0;
    }
  buffPrintCode[n] = 0;
  nReturn = PrintCodeRec(c, n + 1, node->left);
  if(nReturn > 0)
    return nReturn;
  buffPrintCode[n] = 1;
  nReturn = PrintCodeRec(c, n + 1, node->right);
  return nReturn;
}

