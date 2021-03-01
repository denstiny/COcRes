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
		void Show_Select_Class() ;  //  显示所有员工
		~WorkerManger();  // 析构函数
};

