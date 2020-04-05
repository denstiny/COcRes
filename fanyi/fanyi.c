#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#define URL "https://fanyi.baidu.com/#zh/en/"
void *fanyi(char str);

int main()
{
    char* strin = malloc(sizeof(BUF));
    fgets(strin,sizeof(strin),stdin);
    strin = fanyi(strin);
    puts(strin);

    return 0;
}

void* fanyi(char str)
    //翻译
{
    char

    return str;
}
