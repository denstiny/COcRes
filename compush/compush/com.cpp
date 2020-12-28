//压缩程序



#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<strings.h>

const char *str = new char[100];
int number;
while(number < 100)
{
	*(str + number) = [a - z];
}

void StrChar(char *chr);

int main(int argc,char *argv[])  // argv[1] --> 源文件 argv[2] --> 新文件
{
	char *da = new char[1024];
	if(argc < 2)
	{
		printf("未检测到文件");
		exit(1);
	}
	FILE *file = NULL;
	file = fopen(argv[1],"rb");
	if(file)
	{
		fgets(da,sizeof(da),file);
		char *st = da;
		while(*(++st)!='\n')
			std::cout <<  st << std::endl;
	}
	else
		std::cout << "打开文件失败" << std::endl;
	fclose(file);
	delete [] da;
	return 0;
}
