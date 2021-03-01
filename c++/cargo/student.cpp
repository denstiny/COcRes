#include <iostream>
#include <string>
using namespace std;
int main(int argc,char *argv[])
{
	cerr << "what is your first name?" ;
	string first_name;
	getline(cin,first_name);

	cerr << "what is your last name?" ;
	string last_name;
	getline(cin,last_name);

	cerr << "what letter grade do you deserve?" ;
    char grade;
	cin.get(grade);

	cerr << "what is you age?";
	int age;
	cin >> age;
	cout << "name: " << first_name<< " " << last_name << endl;
	cout << "Grade: " << grade << endl;
	cout << "Age: " <<age << endl;



	return 0;
}
