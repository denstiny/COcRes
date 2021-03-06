// #include<stdio.h>
// typedef struct Date{
//     int *array;
//     int size;
// }Array;
// int array_size(const Array *p);
// int main(int argc, char const *argv[])
// {
//     Array a;

//     printf("%d",array_size(&a));
//     return 0;
// }
// Array array_create(int init_size)
// {
//     Array a;
//     a.size=init_size;
//     a.array=(int *)malloc(sizeof(int)*a.size);
//     return a;
// }
// //封装
// int array_size(const Array *p)
// {
//     (*p).size=1;
//     return p->size;
// }
// #include<stdio.h>
// int main(int argc, char const *argv[])
// {
//     get();
//     int a,b;
//     printf("in main() &a=%d,&b=%d\n",&a,&b);
//     return 0;
// }
// void get()
// {
//     int a,b;
//     printf("in get() &a=%d,&b=%d\n",&a,&b);
// }


#include<stdio.h>
int main(int argc, char const *argv[])
{
    int sum=0;
    int count=0;
    int x=-1;
    scanf("%d",&x);
    printf("%d\n",x);
    while(x!=-1)
    {
        sum+=x;
        count++;
        scanf("%d",&x);
    }
    printf("sum/count=%d\n",sum/count);
    return 0;
}


// #include<stdio.h>
// int main(int argc, char const *argv[])
// {
//     int array[100];
//     int count=0;
//     double sum=0;
//     int x;
//     scanf("%d",&x);
//     while(x!=-1)
//     {
//         array[count]=x;
//         sum+=x;
//         count++;
//         scanf("%d",&x);
//         getchar();
//     }
//     if(count>0)
//     {
//         printf("%f",sum/count);
//     }
//     return 0;
// }

