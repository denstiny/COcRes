#include<stdio.h>
#include<stdlib.h>
#ifdef linux
char getche()
{
        char c;
        system("stty -icanon");
        c=getchar();
        system("stty icanon");
        return c;
}
#elif WIN32 || _WIN32
#include<conio.h>
#endif
int input();
int main()
{
        int a = 0,b = 0,nu = 0;
        while(nu < 10)
        {
                a = input();
                b = input();
                printf("%d\n",a+b);
                nu ++;
        }
        return 0;
}
int input()
{
        int num[5] = {0},sum = 0;
        for(int i = 0;(num[i]=getche()) !=  ' ';i++)
                num[i] = num[i]-'0';
        for(int i = 0;num[i] != ' ';i++)
                sum =sum*10+num[i];
        return sum;
}

