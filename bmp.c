#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

void save_image(char *file,unsigned char* bmp,int w ,int h)  
{  
    BITMAPFILEHEADER file_header;
    BITMAPINFODEADER info_header;
    
    memset(&file_header, 0x0, sizeof(BITMAPFILEHEADER));
    memset(&info_header, 0x0, sizeof(BITMAPINFODEADER));
    
    /* Init BITMAPFILEHEADER */
    ((unsigned char *)&file_header.bfType)[0] = 0x42;
    ((unsigned char *)&file_header.bfType)[1] = 0x4d;
    
    file_header.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFODEADER) 
    	+ 3*w*h;
    file_header.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFODEADER);
    
    /* Init BITMAPINFODEADER */
    info_header.biSize = 40;
    info_header.biWidth = w;
    info_header.biHeight = h;
    info_header.biPlanes = 1;
    info_header.biBitCount = 24;
    info_header.biXPelsPerMeter = 0x120b;
    info_header.biYPelsPerMeter = 0x120b;
    
    FILE* fd = NULL;  
  
    fd = fopen(file,"wb+");  
    if(fd == NULL)  
    {  
        return;  
    }  
    else  
    {  
        fwrite(&file_header,sizeof(file_header),1,fd);
        fwrite(&info_header,sizeof(info_header),1,fd);  
        fwrite(bmp,3*w*h,1,fd);
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
	
	save_image("tmp.bmp", buf, IMAGE_WIDTH, IMAGE_HEIGHT);
	
	return 0;
}





