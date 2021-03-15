#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Perjet {
	public:
		int i ;
		char b;
		Perjet(int a,char b){
			i = a;
			this->b = b;
		}
};
template<typename T>
void showCPrint(T t) {
	cout << t.i << " " << t.b << endl;
}


int ma() {
	vector<Perjet> p;
	Perjet a(1,'2');
	Perjet b(3,'4');
	Perjet c(5,'5');
	p.push_back(a);
	p.push_back(b);
	p.push_back(c);
	
	for(vector<Perjet>::iterator s = p.begin(); s != p.end();s++) {
		cout << s->i << "   " << s->b << endl;
	}
	
	for_each(p.begin(), p.end(), showCPrint<Perjet>);
	
	return 0;
}
int showprint(int v) {
	cout << v << endl;
	return v;
}

int main(int argc,char *argv[]) {
	vector<int> list {1,2,3,4,5,6,7,8,9};
	for_each(list.begin(), list.end(), showprint) ;

	cout << "ma funcun" << endl;
	ma();
	return 0;
}



