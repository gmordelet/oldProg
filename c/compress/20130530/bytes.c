#include"headers.h"

#define BUFSIZE 100

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
void WriteComp(int fdRead, int fdWrite, unsigned char **code)
{
  int byte, n, i;
  unsigned char buffRead[BUFSIZE];

  lseek(fdRead, 0, 0);
  while((n = read(fdRead, buffRead, BUFSIZE)) != 0)
    {
      i = 0;
      while(i < n)
	{
	  WriteCompByte(fdWrite, buffRead[i++], code);
	}
    }
  FlushBuff(fdWrite);
}

unsigned int counter = 0;
unsigned char buffWrite = 0;
unsigned int buffWriteCounter = 0;

void WriteCompByte(int fdWrite, int byte, unsigned char **code)
{
  int i, j, n;

  i = 0;
  n = code[byte][0];
  j = 0;
  while(n-- > 0)
    {
      buffWrite |= (0 | code[byte][i++ + 1]) << 7 - counter++;
      if(counter == 8)
	{
	  buffReadWrite[buffWriteCounter++] = buffWrite;
	  buffWrite = 0;
	  j = 0;
	  counter = 0;
	  if(buffWriteCounter == BUFSIZE)
	    {
	      write(fdWrite, buffReadWrite, BUFSIZE);
	      buffWriteCounter = 0;
	    }
	}
    }
}

unsigned buff[8] = {0};

void FlushBuff(int fdWrite)
{
  unsigned char temp;
  if(buffWriteCounter)
    {
      write(fdWrite, buffReadWrite, buffWriteCounter);
      buffWriteCounter = 0;
    }
  if(counter)
    {
      write(fdWrite, &buffWrite, 1);
    }
}

//ReadByteDecomp
/*
  Lit les compteurs de bytes dans un fichier compressé
 */
void ReadBytesDecomp(int fdRead, unsigned long *byteArr, unsigned long *total)
{
  int i, j;
  unsigned long count;
  unsigned char buffRead[(0xFF + 1) * 8] = {0};
  
  int n = read(fdRead, buffRead, (0xFF + 1) * 8);

  for(i = 0; i <= 0xFF; ++i)
    {
      for(j = 0, count = 0; j < 8; ++j)
	{
	  count += buffRead[8 * i + j] * _2power(8 * j);
	}
      byteArr[i] = count;
    }
  for(*total = 0, i = 0; i <= 0xFF; ++i)
    {
      *total += byteArr[i];
    }
}

void PrintDecomp(node *root, unsigned long total, int fdRead, int fdWrite)
{
  int byte, n;
  node *pNode = root;
  
  buffWriteCounter = 0;

  while(total > 0)
    {
      byte = GetBit(fdRead);
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
	  buffReadWrite[buffWriteCounter++] = pNode->c;
	  if(buffWriteCounter == BUFSIZE)
	    {
	      write(fdWrite, buffReadWrite, BUFSIZE);
	      buffWriteCounter = 0;
	    }
	  pNode = root;
	  --total;
	}
    }
  //flush
  write(fdWrite, buffReadWrite, buffWriteCounter);
}

unsigned char buffRead[BUFSIZE];

//GetBit
/*
Recupere le prochain bit d'un fichier à chaque appel
Retourne 0 pour 0, un int > 0 pour un 1, ou EOF
 */
int GetBit(int fdRead)
{
  static int buff;
  static int count = 7;
  static int buffReadCounter = BUFSIZE;

  if(count < 0)
    {
      count = 7;
      ++buffReadCounter;
    }

  if(buffReadCounter == BUFSIZE)
    {
      read(fdRead, buffRead, BUFSIZE);
      buffReadCounter = 0;
    }

  return (1 << count--) & buffRead[buffReadCounter];
}
