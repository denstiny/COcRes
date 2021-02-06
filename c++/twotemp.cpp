#include<iostream>
#include <type_traits>
#include <typeinfo>
using namespace std;
template <typename T>
T Swap(T &a,T &d);
template <typename T>
int Swap(T &a,T &d,T & n);
template<typename T>
int Swap(T &t)
{
	 if(typeid(T) == typeid(int))
			return 1;
	 return 2;
}
int main(int argc,char *argv[])
{
	 int n = 10, s = 1;
	 char cs = 's',cn = 'n';
	 
	 cout << cn << Swap(cn) << endl;
	 
	 cout << cn << cs << Swap(cn,cs,cs) << endl;
	return 0;
}

template <typename T>
T Swap(T &a,T &d)
{
	 T ss;
	 ss = d;
	 d = a;
	 a = ss;
	 return a;

}
template <typename T>
int Swap(T &a,T &d,T & n)
{
	 if(is_same<T, int>::value)
	 {
			return 1;
	 }
	 return 2;
}
