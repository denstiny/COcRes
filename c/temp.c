#include<stdio.h>
int main(int argc, char const *argv[])
{
    char *str1="皆有可能\n";
    char *str2="草船借箭\n";
    char *str3="万箭齐发\n";
    char *str4="梦回故里\n";
    char *p[4]={
        str1,str2,str3,str4
    };
    for(int i=0;i<4;i++)
    {
        printf("%s\n",p[i]);
    }
    return 0;
}



