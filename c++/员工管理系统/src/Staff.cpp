#include <iostream>
#include "../include/Staff.h"
using namespace std;

WorkerManger::WorkerManger() {
}

void WorkerManger::Show_Menu() {
	cout << "*********************" << endl;
	cout << "******* 0 退出 ********" << endl;
	cout << "******* 1 添加 ********" << endl;
	cout << "******* 2 显示 ********" << endl;
	cout << "******* 4 修改 ********" << endl;
	cout << "******* 5 查找 ********" << endl;
	cout << "******* 6 排序 ********" << endl;
	cout << "******* 7 清空 ********" << endl;
	
}

WorkerManger::~WorkerManger() {
}
