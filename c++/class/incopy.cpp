#include<iostream>
using namespace std;



class Person
{
	public:
		
		Person() {
			cout << "Person 默认构造函数" << endl;
		}


		Person(int M_age,int M_height) {
			cout << "Person 有参数构造函数 " << endl;
			age = M_age;
			height = new int(M_height);
		  cout << age << " | " << *height << endl;
		}


		Person(int M_age) {
			cout << "Person 有参数构造函数 " << endl;
			age = M_age;
		}


		~Person() {
		  cout << "析够函数调用" <<  endl;
		  if(height != nullptr)
		  	cout << age << " | " << *height << endl;
		  else
		  	cout << age << endl;

		 // if(height != nullptr)
		 // 	delete height;
		}//
	private:
		int age; // 年龄
		int *height; // 身高
};

int main(int argc,char *argv[])
{
	//Person p1(18,19);
	
	Person p2(10);
	return 0;
}
