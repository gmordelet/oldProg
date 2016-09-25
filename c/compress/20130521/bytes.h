#include"tree.h"

#ifndef DEF_BYTES
#define DEF_BYTES

void ReadBytes(char *, unsigned long *);
void WriteBytesArr(FILE *, unsigned long *);
void WriteByteCount(unsigned long, FILE *);
unsigned long _2power(int);
void WriteComp(FILE *, FILE *, unsigned char**);
void WriteCompByte(FILE *, int, unsigned char **);
void FlushWrite(FILE *);
void BuffToZero();
unsigned char BuffToNum();
void ReadBytesDecomp(FILE *, unsigned long *, unsigned long *);
void PrintDecomp(node *, unsigned long, FILE *, FILE *);
int GetBit(FILE *);

#endif
