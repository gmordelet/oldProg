#include"headers.h"

#define BUFSIZE 1000

//InitByteArr
/*
  Remet le tableau de bytes à zero
 */
void InitByteArr(unsigned long *byteArr)
{
  int i;
  for(i = 0; i <= 0xFF; ++i)
    {
      byteArr[i] = 0;
    }
}

void ReadBytes(char *name, unsigned long *ByteArr)
{
  int fd, n, i;
  unsigned char buff[BUFSIZE];

  fd = open(name, O_RDONLY);
  if(fd == -1)
    {
      printf("Erreur : ouverture %s\n", name);
      exit(EXIT_FAILURE);
    }
  while(n = read(fd, buff, BUFSIZE))
    {
      while(--n >= 0)
	{
	  ++ByteArr[buff[n]];
	}
    }
  close(fd);
}

void WriteBytesArr(FILE *fp, unsigned long *byteArr)
{
  int i;
  unsigned long total;

  for(i = 0; i <= 0xFF; ++i)
    {
      WriteByteCount(byteArr[i], fp);
    }
}

void WriteByteCount(unsigned long num, FILE *fp)
{
  int i;
  for(i = 0; i < 8; ++i)
    {
      fputc(num % 256, fp);
      num /= 256;
    }
}

unsigned long _2power(int n)
{
  unsigned long temp = 1;
  while(n-- > 0)
    {
      temp <<= 1;
    }
  return temp;
}

static unsigned int counter = 0;
static unsigned char buff[8] = {0};

void WriteComp(FILE *fpRead, FILE *fpWrite, unsigned char **code)
{
  int byte;

  while((byte = fgetc(fpRead)) != EOF)
    {
      WriteCompByte(fpWrite, byte, code);
    }
  if(counter)
    {
      fputc(BuffToNum(), fpWrite);
    }
  fflush(fpWrite);
}

void WriteCompByte(FILE *fpWrite, int byte, unsigned char **code)
{
  int i = 0;
  int n = code[byte][0];

  while(n-- > 0)
    {
      if(counter == 8)
	{
	  fputc(BuffToNum(), fpWrite);
	  BuffToZero();
	  counter = 0;
	}
      buff[counter++] = code[byte][i++ + 1];
    }
}

void BuffToZero()
{
  int i;
  while(i < 8)
    {
      buff[i++] = 0;
    }
}

unsigned char BuffToNum()
{
  unsigned char num = 0;
  int i = 0;
  while(i < 8)
    {
      num |= (0 | buff[i]) << 7 - i;
      ++i;
    }
  return num;
}

//ReadByteDecomp
/*
  Lit les compteurs de bytes dans un fichier compressé
 */
void ReadBytesDecomp(FILE *fp, unsigned long *byteArr, unsigned long *total)
{
  int i, j;
  unsigned long count;
  
  *total = 0;
  for(i = 0; i <= 0xFF; ++i)
    {
      for(j = 0; j < 8; ++j)
	{
	  buff[j] = fgetc(fp);
	}
      for(j = 0, count = 0; j < 8; ++j)
	{
	  count += buff[j] * _2power(8 * j);
	}
      byteArr[i] = count;
    }
  for(*total = i = 0; i <= 0xFF; ++i)
    {
      *total += byteArr[i];
    }
}

void PrintDecomp(node *root, unsigned long total, FILE *fpRead, FILE *fpWrite)
{
  int byte;
  node *pNode = root;
  
  while((byte = GetBit(fpRead)) != EOF && total > 0)
    {
      if(!byte)
	{
	  pNode = pNode->left;
	}
      else
	{
	  pNode = pNode->right;
	}
      if(pNode->c != -1)
	{
	  fputc(pNode->c, fpWrite);
	  pNode = root;
	  --total;
	}
    }
}

//GetBit
/*
Recupere le prochain bit d'un fichier à chaque appel
Retourne 0 pour 0, un int > 0 pour un 1, ou EOF
 */
int GetBit(FILE *fpRead)
{
  static int buff;
  static int count = -1;

  if(count < 0)
    {
      count = 7;
      buff = fgetc(fpRead);
    }

  if(buff == EOF)
    return EOF;
  return (1 << count--) & buff;
}
