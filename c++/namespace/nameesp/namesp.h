#ifndef NAESP_H_
#define NAESP_H_
#include <string>
namespace pers {
	 struct person
	 {
			std::string fname;
			std::string lname;
	 };
	 void GetPerson(person &);
	 void ShowPeron(const person &);
}
namespace debts
{
	 using namespace pers;
	 struct Debt
	 {
			person name;
			double amount;
	 };
	 void Getdebt(Debt &);
	 void showDebt(const Debt ar[],int n);
}
#endif
