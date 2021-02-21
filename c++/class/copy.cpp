#include<iostream>
using namespace std;

class Person
{
public:

  Person() {
    cout << "Person 构造函数" << endl;
  }

  Person(const Person &p) {
    // 拷贝构造
		cout << "拷贝构造" << endl;
    cout << p.age << endl;
    age = p.age;
  }

  void setAge(int a) {
    age = a;
  }
  void PAge()
  {
    cout << age << endl;
  }
private:
  int age;
};

void test()
{
  Person p;
  p.setAge(10);
  Person strr(p);
  strr.PAge();
  
}
void Ptest(Person p)
{
}
void test1()
{
	Person p;
	Ptest(p);
}

Person test2()
{
	Person p1;
	cout << &p1 << endl;
	return p1;
}
int main()
{
  //test();
	Person p = test2();
	cout << &p << endl;
  return 0;
}
