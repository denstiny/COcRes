#include<iostream>
using namespace std;
namespace Jakc {
int todo;
}
int main(int argc,char *argv[])
{
	 //using Jakc::todo;
	 int todo; // 由于using 生命将名声添加到局部生命区域中，因此无法在这个局部声明，重复定义相同的fetch
	 todo = 10;
	 cout << todo << endl;
	 cout << &todo << endl;
	 cout << &Jakc::todo << endl;
	 return 0;
}
