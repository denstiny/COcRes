#include <stdio.h>
#include <stdlib.h>
float max(float temp_one,float temp_tow); //加法
float max1(float temp_one,float temp_tow); //乘法

int main(int argc,char *argv[])
{
	float a,b;
	printf("Input tow number:");
	scanf("%f%f",&a,&b);
	printf("加法 %.1f\n",max(a,b));
	printf("乘法 %.1f\n",max1(a,b));
	
	return 0;
}
float max(float temp_one,float temp_tow) //加法
{
	return temp_one+temp_tow;
}
float max1(float temp_one,float temp_tow) //加法
{
	return temp_one*temp_tow;
}
