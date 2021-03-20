/**
 * src/Staff.cpp
 * Copyright (c) 2021 denstiny Anonymity <2254228017@qq.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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
	// 同步员工人数
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
	len++;
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
	for(int i=0;i < len && !obs.eof();i++) {
		ReadFileClass(p);
		//printf("%s %d %s \n",p.EmployName,p.EmployAge,p.Emaployposition);
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
		len = 0;
		obs.open(FILENAME,ios::binary | ios::app | ios::in);
		if(!obs.is_open()) {
			obs.open(FILENAME,ios::out | ios::in | ios::out);
			if(!obs.is_open()) {
			}
		}
	}
}

// 查找员工数据
bool Company::SeleEmploy(char bufName[100],Employees& p) {
	SetLenEmploy();
	for(int i = 0;i < len && !obs.eof() ;i++) {
		ReadFileClass(p);
		if(!strcmp(bufName, p.EmployName))
			return true;
	}
	return false;
}
// 删除员工信息
void Company::DeleEmploy() {
	char bufName[100];
	Employees p,* header = new Employees[len-1];
	cout << "Input EmployName in file select: ";
	cin >> bufName;
	if(SeleEmploy(bufName, p)) {
		cout << "搜索结果: " << endl;
		cout << p.EmployName << " " << p.EmployAge << " " << p.Emaployposition << endl;
		cout << "if you delect that (y/n):";
		char temp;
		cin >> temp;
		if(temp == 'y') {
			// 临时保存员工数据，提取出要删除的数据，然后保存
			obs.seekg(0);
			SaveEmpoly(header, p);
			for (int i =1 ; i < 3; i++) {
			printf("\nheader ==>  %s  %s \n",header->EmployName,header->Emaployposition);
			}
			obs.seekg(0);
			// 清空员工数据 
			CloseCompany();
			obs.seekg(0);
			// 重新写入
			cout << "显示员工数据 " << templen << endl;
			for(int i=0;i < templen;i++) {
				printf("class name %s %s \n",header->EmployName,header->Emaployposition);
				WriteFileClass(*(header+i));
			}
		}
	}else {
		cout << "error! No select Employ" << endl;
	}
	delete [] header;
}

// 临时保存员工数据
Employees * Company::SaveEmpoly(Employees *p,Employees s) {
	// 									存储数据 	提取数据
	templen = 0;
	Employees temp;
	for(int i = 0,n = 0;i < len && !obs.eof() ;i++) {
		ReadFileClass(temp);
		// 如果 找到了数据执行跳过，不保存
		if(!strcmp(s.EmployName, temp.EmployName)) {
			continue;
		}
		*(p+n) = temp;
		//printf("-- temp name : %s  -- S name : %s \n",(p+n)->EmployName,temp.EmployName);
		//printf("%p %p",p->EmployName,temp.EmployName);
		n++;
		templen++;
	}
	return p;
}


// 修改员工数据
void Company::ModifyEmploy() {
	char bufName[100];
	Employees p,* header = new Employees[len];
	cout << "Input EmployName in file select : " ;
	cin >> bufName;
	if(SeleEmploy(bufName, p)) { // 查找数据
		cout << "搜索结果: "  << endl;
		cout << p.EmployName << " " <<  p.EmployAge << " "  << p.Emaployposition << endl;
		cout << "if you modify that (y/n): " ;
		char temp;
		cin >> temp;
		if(temp == 'y') {
			obs.seekg(0);
			// 修改数据，并临时存储在header中
			ModifySaveEmpoly(header, p);
			obs.seekg(0);
			// 清空员工数据
			CloseCompany();
			obs.seekg(0);
			// 保存
			for(int i=0;i < templen;i++) {
				//printf("\n write header ==> %s %s \n",(header+i)->EmployName,(header+i)->Emaployposition);
				WriteFileClass(*(header+i));
			}
	}
	}else {
	cout << "error! No select Employ" << endl;
	}
	delete [] header;
}

// 修改函数存储
Employees* Company::ModifySaveEmpoly(Employees *p,Employees s) {
	Employees temp;
	templen = 0;
	for(int i = 0,n = 0;i < len && !obs.eof();i++) {
		ReadFileClass(temp);
		if(!strcmp(s.EmployName, temp.EmployName)) {
			// 如果找到数据则修改
			cout << "input name age postition(name = 'q':exit)" << endl;
			cin >> temp.EmployName;
			
			if(*temp.EmployName == 'q') 
				return nullptr;
				
			cin >> temp.EmployAge;
			cin >> temp.Emaployposition;
		}
		*(p+n) = temp;
		n++;
		templen++;
	}
	return p;
}
