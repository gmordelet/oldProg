#ifndef DEF_BITMAP
#define DEF_BITMAP

typedef struct BitmapInfo{
  char *signature;
  unsigned int fileSize;
  unsigned int reserved1;
  unsigned int reserved2;
  unsigned int offset;
  unsigned int DIBHeaderSize;
  int width;
  int height;
  unsigned int bitsPerPixel;
  unsigned int compression;
  unsigned int imageSize; //raw bitmap data size
  int horizontalResolution;
  int verticalResolution;
  unsigned int colorPaletteNumber;
}BitmapInfo;

int BitmapGetInfo(int, BitmapInfo *);
void BitmapPrintInfo(BitmapInfo);

#endif
