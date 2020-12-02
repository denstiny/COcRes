#include <iostream>


class Student
{
	public:
		std::string student_name;
		int student_id;
		void Cont_Student()
		{
			std::cout << "名字" << student_name << std::endl;
			std::cout << "学号" << student_id << std::endl;
		}
};


int main()
{
	Student cl = {"zhag",1};
	cl.Cont_Student();
	return 0;
}
