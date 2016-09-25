#include"tree.h"

#ifndef DEF_BYTES
#define DEF_BYTES

void ReadBytes(int, unsigned long *);
void WriteBytesArr(int, unsigned long *);
void WriteByteCount(int, unsigned char *, unsigned long);
unsigned long _2power(int);
void WriteComp(FILE *, int, unsigned char**);
void WriteCompByte(int , int, unsigned char **);
void FlushWrite(FILE *);
void BuffToZero();
unsigned char BuffToNum();
void ReadBytesDecomp(FILE *, unsigned long *, unsigned long *);
void PrintDecomp(node *, unsigned long, FILE *, FILE *);
int GetBit(FILE *);
void FlushBuff(int);

#endif
