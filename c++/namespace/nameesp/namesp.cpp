#include <cstdlib>
#include<iostream>
#include <pthread.h>
#include "namesp.h"

namespace pers {
	 using std::cout;
	 using std::cin;
	 void GetPerson(person &rp)
	 {
			cout << "Enter first name: ";
			cout << rp.fname;
			cout << "Enter last name: ";
			cin >> rp.lname;
	 }
	 void ShowPeron(const person & rp)
	 {
			std::cout << rp.lname << " ," << rp.fname;
	 }
}
namespace debts {
	 void Getdebt(Debt &rd)
	 {
			GetPerson(rd.name);
std:cout << "Endter debt : ";
		std::cin >> rd.amount;
	 }
	 void showDebt(const Debt &rd)
	 {
			ShowPeron(rd.name);
			std::cout << ": $" << rd.amount << std::endl;
	 }
	 double sumBebts(const Debt ar[],int n)
	 {
			double total = 0;
			for (int i = 0;i < n ; i++)
				 total += ar[i].amount;
			return total;
	 }
}
int main(int argc,char *argv[])
{
	 return 0;
}
