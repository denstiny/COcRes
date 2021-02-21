#include <exception>
#include<iostream>
using namespace std;

class Perjet{
	public:
		Perjet(int a,int b,int c):Ma(a),Mb(b),Mc(c) {}
		void Pperjet(){
			cout << Ma << " | " << Mb << " | "  << Mc << " | " << endl;
		}
	private:
		int Ma;
		int Mb;
		int Mc;
};


int main(int argc,char *argv[])
{
	Perjet p(10,20,40);
	p.Pperjet();
	return 0;
}
