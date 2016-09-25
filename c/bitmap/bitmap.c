#include"bitmap.h"
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int BitmapGetInfo(int fd, BitmapInfo *bitmapInfo)
{
  unsigned char buff[54];
  int n;

  //ne gere que les fichiers bmp ayant un entete de 54bits
  lseek(fd, 0, SEEK_SET);
  if(read(fd, buff, 54) != 54 || buff[14] != 40)
    {
      return -1;
    }

  bitmapInfo->signature = malloc(3);
  bitmapInfo->signature[0] = buff[0];
  bitmapInfo->signature[1] = buff[1];
  bitmapInfo->signature[2] = '\0';

  bitmapInfo->fileSize = buff[2] | buff[3] << 8 | buff[4] << 16 | buff[5] << 24;

  bitmapInfo->reserved1 = buff[6] | buff[7] << 8;
  bitmapInfo->reserved2 = buff[8] | buff[9] << 8;

  bitmapInfo->offset = buff[10] | buff[11] << 8 | buff[12] << 16 | buff[13] << 24;

  bitmapInfo->DIBHeaderSize = buff[14] | buff[15] << 8 | buff[16] << 16 | buff[17] << 24;

  bitmapInfo->width = buff[18] | buff[19] << 8 | buff[20] << 16 | buff[21] << 24;
  bitmapInfo->height = buff[22] | buff[23] << 8 | buff[24] << 16 | buff[25] << 24;

  bitmapInfo->bitsPerPixel = buff[28] | buff[29] << 8;

  bitmapInfo->compression = buff[30] | buff[31] << 8 | buff[32] << 16 | buff[33] << 24;

  bitmapInfo->imageSize = buff[34] | buff[35] << 8 | buff[36] << 16 | buff[37] << 24;

  bitmapInfo->horizontalResolution = buff[38] | buff[39] << 8 | buff[40] << 16 | buff[41] << 24;
  bitmapInfo->verticalResolution = buff[42] | buff[43] << 8 | buff[44] << 16 | buff[45] << 24;

  bitmapInfo->colorPaletteNumber = buff[46] | buff[47] << 8 | buff[48] << 16 | buff[49] << 24;

  return 0;
}

void BitmapPrintInfo(BitmapInfo bitmapInfo)
{
  printf("Bitmap File Header\nsignature = %s\nfileSize = %u\nreserved1 = %u\nreserved2 = %u\noffset = %u\n\
DIB\nDIBHeaderSize = %u\nwidth = %d\nheight = %d\nbitsPerPixel = %u\ncompression = %u\nimageSize = %u\nhorizontalResolution = %d\nverticalResolution = %d\nbuffPaletteNumber = %u\n", 
	 bitmapInfo.signature, bitmapInfo.fileSize, bitmapInfo.reserved1, bitmapInfo.reserved2, bitmapInfo.offset,
	 bitmapInfo.DIBHeaderSize, bitmapInfo.width, bitmapInfo.height, bitmapInfo.bitsPerPixel, bitmapInfo.compression, bitmapInfo.imageSize, bitmapInfo.horizontalResolution, bitmapInfo.verticalResolution, bitmapInfo.colorPaletteNumber);

}
