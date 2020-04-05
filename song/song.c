#include<stdio.h>
#include<unistd.h>
#include<string.h>
char  One_Story();
char  Tow_Story();
void  Sleep();
void  Print();
int main()
{
    One_Story();
    return 0;
}
void Print(char Str[]){
    int size,sizeFor;
    sizeFor = strlen(Str);
    for(size = 0; size < sizeFor; size++)
    {
        printf("%c",*(Str+size));
    }

}
void Sleep()
{
    int a,b;
    for(a = 0;a < 10000;a++)
        for(b = 0;b < 1200;b++);
}
char Tow_Story()
{
}
char One_Story()
{
    char a;
    FILE * fq = fopen("song.txt","rt");
    while((a = fgetc(fq) )!= EOF)
    {
        putchar(a);
        Sleep();

    }
    
    fclose(fq);
    

}
