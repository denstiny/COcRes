#include <iostream>
#include <fstream>
#include "../include/Staff.h"
using namespace std;

WorkerManger::WorkerManger() {
}

void WorkerManger::Show_Menu() {
	cout << "*********************" << endl;
	cout << "******* 0 退出 ********" << endl;
	cout << "******* 1 添加 ********" << endl;
	cout << "******* 2 显示 ********" << endl;
	cout << "******* 3 删除 ********" << endl;
	cout << "******* 4 修改 ********" << endl;
	cout << "******* 5 查找 ********" << endl;
	cout << "******* 6 排序 ********" << endl;
	cout << "******* 7 清空 ********" << endl;
	
}
void WorkerManger::Show_Select_Class() {
	Perjet p;
	fstream obs("test",ios::binary | ios::in);
	
	if(!obs.is_open()) {
		cout << "数据不存在!" << endl;
		return;
	}
	
	while(!obs.eof()) {
		obs.read((char *)&p, sizeof(Perjet));
		cout << "员工id: " << p.id << " " << "员工名字 : " << p.class_name  << endl;
	}
}

WorkerManger::~WorkerManger() {
	Show_Menu();
}
