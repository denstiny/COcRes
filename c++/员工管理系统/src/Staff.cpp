#include <cstdio>
#include <stdio.h>
#include <cstdlib>
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
		exit(1);
	}
	
	while(!obs.eof()) {
		obs.read((char *)&p, sizeof(Perjet));
		cout << "员工id: " << p.id << " " << "员工名字 : " << p.class_name  << endl;
	}
	cout <<  "按任意键返回..."  << endl;
	getchar();
	obs.close();
}

void WorkerManger::Add_Members() {
	fstream obs;
	Perjet p;
	obs.open("test",ios::binary | ios::app);
	if(!obs.is_open()) {
		cout << "添加数据失败，文件不存在" << endl;
		exit(1);
	}
	
	
	while (1) {
		cout << "输入员工姓名: " << endl;
		cin >> p.class_name ;
		cout << "输入员工id: " << endl;
		cin >> p.id;
		obs.write((const char *)&p, sizeof(Perjet));
		cout << "是否继续输入!" << endl;
	}
	obs.close();
}
void WorkerManger::Delelat_Menbers() {
}
WorkerManger::~WorkerManger() {
	Show_Menu();
}
