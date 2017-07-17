#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

void SaveImage(char *file,unsigned char* bmp,int w ,int h)  
{  
    int i = 0;  
    char color = 0;  
    char end[2] = {0,0};  
    char patte[1024] = {0};  
    int pos = 0;  
  
    unsigned char heard[54] = {0x42,0x4d,0x30,0x0C,0x01,0,0,0,0,0,0x36,4,
    	0,0,0x28,0,0,0,0xF5,0,0,0,0x46,0,0,0,0x01,0,8,0,0,0,0,0,0xF8,
    	0x0b,0x01,0,0x12,0x0b,0,0,0x12,0x0b,0,0,0,0,0,0,0,0,0,0};  
    int size = w*h;  
    int allsize = size +1080;  
  
    heard[2] = allsize&0xFF;  
    heard[3] = (allsize>>8)&0xFF;  
    heard[4] = (allsize>>16)&0xFF;  
    heard[5] = (allsize>>24)&0xFF;  
  
    heard[18] = w&0xFF;  
    heard[19] = (w>>8)&0xFF;  
    heard[20] = (w>>16)&0xFF;  
    heard[21] = (w>>24)&0xFF;  
  
    heard[22] = h&0xFF;  
    heard[23] = (h>>8)&0xFF;  
    heard[24] = (h>>16)&0xFF;  
    heard[25] = (h>>24)&0xFF;  
  
    allsize -=1078;  
    heard[34] = allsize&0xFF;  
    heard[35] = (allsize>>8)&0xFF;  
    heard[36] = (allsize>>16)&0xFF;  
    heard[37] = (allsize>>24)&0xFF;  
  
    for(i=0;i<1024;i+=4)  
    {  
        patte[pos++] = color;  
        patte[pos++] = color;  
        patte[pos++] = color;  
        patte[pos++] = 0;  
        color++;  
    }  
  
    FILE* fd = NULL;  
  
    fd = fopen(file,"wb+");  
    if(fd == NULL)  
    {  
        return;  
    }  
    else  
    {  
        fwrite(heard,54,1,fd);  
        fwrite(patte,1024,1,fd);  
        fwrite(bmp,size,1,fd);  
        fwrite(end,2,1,fd);  
    }  
    fclose(fd);  
}

#define IMAGE_HEIGHT	320
#define IMAGE_WIDTH	240

int main(int argc, char **argv)
{
	char *buf;
	
	buf = malloc(IMAGE_HEIGHT*IMAGE_WIDTH*3);
	memset((void *)buf, 0xaa, IMAGE_HEIGHT*IMAGE_WIDTH*3);
	
	SaveImage("tmp.bmp", buf, IMAGE_WIDTH, IMAGE_HEIGHT);
	
	return 0;
}





