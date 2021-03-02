#pragma Staff  // 防止头文件重复加载
#include <iostream>
using namespace std;

class Perjet {
	public:
		int id;
		char class_name[100];
};

class WorkerManger {
	public: 
		friend Perjet;
		WorkerManger();  // 构造函数
		
		void Show_Menu(); // 显示菜单
		
		void Add_Members();  // 添加成员函数
		void Show_Select_Class() ;  //  显示所有员工
		
		void Delelat_Menbers();  // 删除员工信息

		void Select_Menbers();  // 查找员工信息
		~WorkerManger();  // 析构函数
};

