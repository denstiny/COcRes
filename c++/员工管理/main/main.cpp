/**
 * main.cpp
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

#include <iostream>
#include <fstream>
#include "../include/Staff.h"

int main(int argc,char *argv[]) {
	Company entity;
	int swap; // 选择
	while (1) {
		cout << "input choose: ";
		cin >> swap;
		switch (swap) {
			case 1: 
				// 显示菜单
				entity.ShowMenu();
				break;
			case 2:
				entity.AddEmployees();
				// 添加员工数据
				break;
			case 3:
				entity.ObtainEmploy();
				// 获取员工数据
				break;
			case 4:
				entity.CloseCompany();
				// 清空员工数据
				break;
			case 5:
				// 删除员工数据
				entity.DeleEmploy();
				break;
			case 6:
				// 修改员工数据
				entity.ModifyEmploy();
				break;
			case 0:
				return 0;
		}
		entity.obs.clear();
		entity.obs.seekg(0);
		//cout << "obs.seekg(0)" << endl;
	}
	return 0;
}
