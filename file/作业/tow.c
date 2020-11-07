#include<stdio.h>
int main()
{
	float a,b;
	printf("请输入两个数用空格隔开:");
	scanf("%f%f",&a,&b);
	printf("%f + %f=%f\n",a,b,a+b);
	printf("%f - %f=%f\n",a,b,a-b);
	printf("%f x %f=%f\n",a,b,a*b);
	printf("%f %% %f=%f\n",a,b,(float)(a-(int)(a/b)*b));
	return 0;
}
