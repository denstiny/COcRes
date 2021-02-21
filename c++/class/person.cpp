#include<iostream>
#include <string>
using namespace std;

class Person
{
	 public:

			// 共有
			void setName(string strname){
				 name = strname;
			}
			string Pr_name(){
				 return name;
			}
	 private:
			// 私有
			string name;

};
int main(int argc,char *argv[])
{
	 Person p;
	 p.setName("张三");
	 cout << "姓名: " << p.Pr_name() << endl;
	 return 0;
}
