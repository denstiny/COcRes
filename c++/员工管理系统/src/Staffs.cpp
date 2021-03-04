/**
 * File              : Staffs.cpp
 * Author            : denstiny Anonymity <2254228017@qq.com>
 * Date              : 04.03.2021
 * Last Modified Date: 04.03.2021
 * Last Modified By  : denstiny Anonymity <2254228017@qq.com>
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "../include/Staff.h"
using namespace std;

// 显示菜单
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

// 获取员工总人数
void WorkerManger::Sum_Menu() {
	fstream obs(FILENAME,ios::in);
	obs.seekg(0,ios::end);
	int temp = obs.tellg();
	obs.close();
	Employees = temp/sizeof(Perjet);
}

// 插入数据
bool WorkerManger::Add_Members(Perjet &p) {
	cout << "输入 员工姓名 职位(q:退出输入): " << endl;
	cin >> p.class_name;
	if(*p.class_name == 'q'){
	  return false;
	}
	cin >> p.position;
	//cout << p.class_name << " | " << p.position << endl;
	return true;
}

// 写入数据
void WorkerManger::WriteDate() {
	fstream obs(FILENAME,ios::binary | ios::app);
	Perjet p;
	if(!obs.is_open()) {
		cout << "文件打开失败" << endl;
		obs.close();
		return;
	}
	Add_Members(p);
	obs.write((const char *)&p,sizeof(p));
	obs.close();
}

// 清空数据
void WorkerManger::Clear_class() {
	ofstream obs(FILENAME,ios::trunc);
	obs.close();
}

// 读取员工数据
bool WorkerManger::ReadFileMenu(fstream &obs,Perjet& p) {
	if(!obs.is_open() | obs.eof()) {
		cout << "没有文件数据" << endl;
		p.Close();
		return false;
	}
	obs.read((char *)&p, sizeof(p));
	return true;
}

// 创建员工列表
Perjet* WorkerManger::List_employees() {
	fstream obs(FILENAME,ios::binary | ios::in);
	Perjet p;
	Perjet *head,* temp;
	// 读取文件数据
	if(ReadFileMenu(obs,p)) {
		cout << "读取文件数据失败" << endl;
		return nullptr;
	}
	cout << p.class_name << " +++ " << p.position << endl;
	return nullptr;
}



