#ifndef __BMP_H__
#define __BMP_H__

#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>    
#include <fcntl.h>
#include <string.h>

#pragma  pack(push) 
#pragma  pack(1)

typedef struct BITMAPFILEHEADER  
{   
    u_int16_t bfType;   		//0
    u_int32_t bfSize;   		//2
    u_int16_t bfReserved1;   		//6
    u_int16_t bfReserved2;   		//8
    u_int32_t bfOffBits;   		//10
}BITMAPFILEHEADER;			//sizeof(BITMAPFILEHEADER) = 14

typedef struct BITMAPINFOHEADER  
{   
    u_int32_t biSize;   		//0
    u_int32_t biWidth;   		//4
    u_int32_t biHeight;   		//8
    u_int16_t biPlanes;   		//12
    u_int16_t biBitCount;   		//14
    u_int32_t biCompression;   		//16
    u_int32_t biSizeImage;   		//20
    u_int32_t biXPelsPerMeter;   	//24
    u_int32_t biYPelsPerMeter;   	//28
    u_int32_t biClrUsed;   		//32
    u_int32_t biClrImportant;   	//36
}BITMAPINFODEADER;  			//sizeof(BITMAPINFODEADER) = 40

#pragma  pack(pop)

#endif

