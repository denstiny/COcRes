#include "../include/Staff.h"
#include <iostream>
#include <stdio.h>
#include <cstring>

Company::Company() {
	obs.open(FILENAME,ios::binary | ios::app | ios::in);
	if(!obs.is_open()) {
		obs.open(FILENAME,ios::out | ios::in | ios::out);
		if(!obs.is_open()) {
		}
	}
	// 设置员工人数
	SetLenEmploy();
}

Company::~Company() {
	obs.close();
}
void Company::ShowMenu() {
	for (int i = 0; i < 50; i++) cout << endl;
	cout << "  菜单 " << endl;
	cout << " 1 显示菜单 " << endl;
	cout << " 2 添加员工数据 " << endl;
	cout << " 3 显示员工数据 " << endl;
	cout << " 4 清空员工数据 " << endl;
	cout << " 5 删除员工数据 " << endl;
	cout << " 6 修改员工数据 " << endl;
	cout << "员工人数: " << len << endl;
}

// 写入数据
bool Company::WriteFileClass(Employees&p) {
	obs.write((char *)&p, sizeof(Employees));
	SetLenEmploy();
	return true;
}

// 添加数据
bool Company::AddEmployees() {
	Employees p;
	while(1) {
		cout << "input name age postition(name = 'q':exit)" << endl;
		cin >> p.EmployName;
		if(*p.EmployName == 'q') 
			return false;
		cin >> p.EmployAge;
		cin >> p.Emaployposition;
		WriteFileClass(p);
	}
	obs.seekg(0);
	return true;
}

// 读取数据

bool Company::ReadFileClass(Employees &p) {
	obs.read((char *)&p,sizeof(Employees));
	return true;
}

// 获取员工数据

bool Company::ObtainEmploy() {
	Employees p;
	SetLenEmploy();
	for(int i=0;i < len && !obs.eof();i++) {
		ReadFileClass(p);
		printf("%s %d %s \n",p.EmployName,p.EmployAge,p.Emaployposition);
	}
	return true;
}

// 获取员工人数
void Company::SetLenEmploy() {
	obs.seekg(0,ios::end);
	int temp = obs.tellg();
	len = temp/sizeof(Employees);
	obs.clear();
	obs.seekg(0);
}

// 清空员工数据
void Company::CloseCompany() {
	cout << "if you run that(y/n)" ;
	char a;
	cin >> a;
	if(a == 'y'){
		obs.close();
		obs.open(FILENAME,ios::trunc | ios::out);
		obs.close();
		Company();
	}
}

// 查找员工数据
bool Company::SeleEmploy(char bufName[100],Employees& p) {
	SetLenEmploy();
	for(int i = 0;i < len && !obs.eof() ;i++) {
		ReadFileClass(p);
		if(strcmp(bufName, p.EmployName))
			return true;
	}
	return false;
}
// 删除员工信息
void Company::DeleEmploy() {
	char bufName[100];
	Employees p;
	cout << "Input EmployName in file select: ";
	cin >> bufName;
	if(SeleEmploy(bufName, p)) {
		cout << p.EmployName << " " << p.EmployAge << " " << p.Emaployposition << endl;
		cout << "if you delect that (y/n):";
		char temp;
		cin >> temp;
		if(temp == 'y') {
			// 临时保存员工数据，提取出要删除的数据，然后保存
		}
	}else {
		cout << "error! No select Employ" << endl;
	}
}


Employees * Company::SaveEmpoly(Employees &p) {
	// -- to do --
	return &p;
}
