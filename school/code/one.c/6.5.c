#include<stdio.h>
//根据题意需要计算 1 -- 100 的和 加上 1 -- 50 的平方和 加上 1/1 -- 1/10 的和
//定义三个函数
float Request_Number(float number);
float Request_Number2(float number);
float Request_Number3(float number);
int main()
{
	printf("SUM ==> %f",Request_Number(100)+Request_Number2(50)+Request_Number3(10));
	return 0;
}
float Request_Number(float number) //计算和值
{
	float temp_number,temp_sum = 0;
	for(temp_number = 1;temp_number < number;temp_number++)
		temp_sum+=temp_number;
	printf("temp_sum ==>%f\n",temp_sum);
	return temp_sum;
}
float Request_Number2(float number) //计算平方值
{
	float temp_sum = 0;
	for(float temp_number = 1;temp_number <= number;temp_number++)
		temp_sum += temp_number * temp_number;
	printf("temp_sum ==>%f\n",temp_sum);
	return temp_sum;
}
float Request_Number3(float number) 
{
	float temp_sum = 0;
	for(float temp_number = 1;temp_number <= number;temp_number++)
		temp_sum += 1/temp_number;
	printf("temp_sum ==>%f\n",temp_sum);
	return temp_sum;
}
