#include"tree.h"

#ifndef DEF_BYTES
#define DEF_BYTES

void ReadBytes(int, unsigned long *);
void WriteBytesArr(int, unsigned long *);
void WriteByteCount(int, unsigned char *, unsigned long);
unsigned long _2power(int);
void WriteComp(int, int, unsigned char**);
void WriteCompByte(int , int, unsigned char **);
void FlushWrite(FILE *);
void ReadBytesDecomp(int, unsigned long *, unsigned long *);
void PrintDecomp(node *, unsigned long, int, int);
int GetBit(int);
void FlushBuff(int);

#endif
