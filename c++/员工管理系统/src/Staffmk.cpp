#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "../include/Staff.h"
using namespace std;

WorkerManger::WorkerManger() {
	P_Node->class_name = nullptr;
	P_Node->position = nullptr;
	P_Node->id = 0;
	P_Node->next = nullptr;
}

Perjet::~Perjet() {
	delete [] class_name;
	delete [] position;
	delete next;
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
	int len = 0;
	fstream obs("test",ios::binary | ios::in);
	if(!obs.is_open()) {
		cout << "数据不存在!" << endl;
		obs.close();
		return;
	}
	char ch;
	obs >> ch;
	if(obs.eof()) {
		cout << "数据不存在" << endl;
		obs.close();
		return;
	}
	obs.seekg(0,ios::end);
	int a = obs.tellg();
	cout << "文件大小为: " << a << endl;
	cout << "员工人数： " << a/sizeof(Perjet) << endl;
	obs.seekp(0);
	
	while(len < a/sizeof(Perjet)) {
		obs.read((char *)&p, sizeof(Perjet));
		cout << "员工id: " << p.id << " " << "员工名字 : " << p.class_name  << "  员工职位: " << p.position  << endl;
		len++;
	}
	obs.close();
}
// 添加数据
void WorkerManger::Add_Members() {
	fstream obs;
	Perjet p;
	obs.open("test",ios::binary | ios::app);
	if(!obs.is_open()) {
		cout << "添加数据失败，文件不存在" << endl;
		obs.close();
		return;
	}
	for(int a = 1;p.id != 0;a++){
		cout << "输入员工姓名 id 职位(按空格隔开): " ;
		cin >> p.class_name ;
		
		if(*p.class_name == 'q') break;
		p.id = a;
		cin >> p.position;
		obs.write((const char *)&p, sizeof(Perjet));
	}
	obs.close();
}

void WorkerManger::Delelat_Menbers() {
	// 删除数据
}


void WorkerManger::CLear_class() {
	ofstream obs("test",ios::trunc);
	obs.close();
}
WorkerManger::~WorkerManger() {
	cout << "欢迎下次使用学生管理系统" << endl;
}

bool WorkerManger::ReadFileMenu() {
	
	return true;
}
