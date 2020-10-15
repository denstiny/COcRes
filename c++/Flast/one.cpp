/*********************************************************************************
*     File Name           :     one.cpp
*     Created By          :     chroot
*     Creation Date       :     [2020-10-12 11:37]
*     Last Modified       :     [2020-10-12 20:23]
*     Description         :     菜鸟教程 基础语法 
**********************************************************************************/

#include <iterator>
#include<iostream>
using namespace std;
int main1();
int main2();
int main3();
int main()
{
	main3();
	return 0;
}
int main2()
{
	std::cout << "hello world" <<" me" << std::endl;
	printf("hello world\t %d\n",(int)sizeof(int));
	cout << "hello world\n";
	return 0;
}
int main1()
{
	enum color{red,green,blue} c;
	std::cout << "hello world" << c << std::endl;
	printf("%s","asdf\n");
	return 0;
}
int mian3()
{
	int i = 10;
	char s = 's';
	int &r = i;
	return 0;
}
