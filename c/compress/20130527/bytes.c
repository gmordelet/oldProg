#include"headers.h"

#define BUFSIZE 1000

//InitByteArr
/*
  Remet le tableau de bytes à zero
 */
void InitBytesArr(unsigned long *bytesArr)
{
  int i;
  for(i = 0; i <= 0xFF; ++i)
    {
      bytesArr[i] = 0;
    }
}

unsigned char buffReadWrite[BUFSIZE];

//ReadBytes
/*
  Calcul le nombre d'apparitions de chaque bytes dans le fichier associé à fd
  et met le résultat dans byteArr
 */
void ReadBytes(int fd, unsigned long *byteArr)
{
  int n;

  while(n = read(fd, buffReadWrite, BUFSIZE))
    {
      while(--n >= 0)
	{
	  ++byteArr[buffReadWrite[n]];
	}
    }
  close(fd);
}

//WriteBytesArr
/*
Ecrit bytesArr dans un fichier associé à fd
*/
void WriteBytesArr(int fd, unsigned long *bytesArr)
{
  int i;
  unsigned long total;
  unsigned char buffWrite[8];

  for(i = 0; i <= 0xFF; ++i)
    {
      WriteByteCount(fd, buffWrite, bytesArr[i]);
      write(fd, buffWrite, 8);
    }
}

void WriteByteCount(int fd, unsigned char *buffWrite, unsigned long num)
{
  int i;
  for(i = 0; i < 8; ++i)
    {
      buffWrite[i] = num % 256;
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

//WriteComp
/*
  Ecrit le fichier compressé dans le fichier associé à fdWrite
  en se servant du code et du fichier associé à fdRead
  fdRead est replacé au début du fichier
 */
void WriteComp(FILE *fpRead, int fdWrite, unsigned char **code)
{
  int byte;

  BuffToZero();
  while((byte = fgetc(fpRead)) != EOF)
    {
      WriteCompByte(fdWrite, byte, code);
    }
  FlushBuff(fdWrite);
}

unsigned int counter = 0;
unsigned char buff[8];
unsigned int buffWriteCounter = 0;

void WriteCompByte(int fdWrite, int byte, unsigned char **code)
{
  int i, j, n;
  unsigned char buffToNum;

  i = 0;
  n = code[byte][0];
  j = 0;
  buffToNum = 0;

  while(n-- > 0)
    {
      buff[counter++] = code[byte][i++ + 1];
      if(counter == 8)
	{
	  while(j < 8)
	    {
	      buffToNum |= (0 | buff[j]) << 7 - j;
	      ++j;
	    }
	  buffReadWrite[buffWriteCounter++] = buffToNum;
	  buffToNum = 0;
	  j = 0;
	  BuffToZero();
	  counter = 0;
	  if(buffWriteCounter == BUFSIZE)
	    {
	      write(fdWrite, buffReadWrite, BUFSIZE);
	      buffWriteCounter = 0;
	    }
	}
    }
}

void FlushBuff(int fdWrite)
{
  unsigned char temp;
  int i;
  if(buffWriteCounter)
    {
      write(fdWrite, buffReadWrite, buffWriteCounter);
      buffWriteCounter = 0;
    }
  if(counter)
    {
      temp = BuffToNum();
      write(fdWrite, &temp, 1);
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
