#pragma Staff  // 防止头文件重复加载
#include <iostream>
#include <cstring>
#define FILENAME "test"
using namespace std;

class Perjet {
	public:
		int id;
		char class_name[100];
		char position[100];
		Perjet *next;
		Perjet();
		Perjet operator=(Perjet p) {
			strcpy(this->class_name, p.class_name);
			strcpy(this->position, p.position);
			return *this;
		}
		void Close();   // 清空堆区数据
};


class WorkerManger {
	public: 
		Perjet * P_Node;
		friend Perjet; // 友元
		int Employees; // 员工人数

		void Sum_Menu();   // 计算员工人数总和 

		void WriteDate(); // 写入数据

		bool Add_Members(Perjet &p); // 添加数据

		void Show_Menu();   // 显示菜单

		void Clear_class(); // 清空数据

		bool ReadFileMenu(fstream &obs,Perjet& p);  // 读取文件数据

		Perjet* List_employees();   // 创建员工列表
};

