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
	newfile = fopen(argv[2],"wd");
	while(!feof(file))
	{
		fread(strSrc,srcLen,0,file);
		compress(buf,&bufLen,strSrc,srcLen);
		printf("%s\n",buf);
		fwrite(buf,srcLen,0,newfile);
	}
	fclose(file);
	fclose(newfile);
    //printf("Src string:%s\nLength:%ld\n", strSrc, srcLen);
	//
    ///* 压缩 */
    //compress(buf, &bufLen, strSrc, srcLen);

    ///* 解压缩 */
    //uncompress(strDst, &dstLen, buf, bufLen);
    //printf("After UnCompressed Length:%ld\n",dstLen);

    //printf("UnCompressed String:%s\n",strDst);

    return 0;
}
