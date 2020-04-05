#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int a;
}no;
void *asd(int as);
int main()
{
    no *one = malloc(sizeof(no));
    one->a = 12;
    asd(one->a);
    
    return 0;
}
void *asd(int as)
{
    printf("%d",as);
}
