
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <zlib.h>
#define size 1024
int main(int argc,char *argv[])
{
    /* 原始数据 */
    unsigned char strSrc[size] = {0};
    unsigned char buf[1024] = {0};
    unsigned char strDst[1024] = {0};
    unsigned long srcLen = sizeof(strSrc);
    unsigned long bufLen = sizeof(buf);
    unsigned long dstLen = sizeof(strDst);
	FILE * file = NULL,*newfile = NULL;
	file = fopen(argv[1],"rd");
	newfile  = fopen(argv[2],"wd");
	while(!feof(file))
	{
		fgets(buf,bufLen,file);
		uncompress(strDst, &dstLen, buf, bufLen);
		fputs(strDst,newfile);
	}
	fclose(newfile);
	fclose(file);
    //printf("After UnCompressed Length:%ld\n",dstLen);

    //printf("UnCompressed String:%s\n",strDst);

    return 0;
}
