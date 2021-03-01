#include <iostream>
#include <cstdlib>
#include "../include/Staff.h"

using namespace std;

int main(int argc,char *argv[]) {
	
	WorkerManger p;
	int chios;
	cout << "输入你的选择" << endl;
	cin >> chios;
	
	p.Show_Menu(); 
	while (1) {
		switch (chios) {
			case 0: // 退出
				return 0;
			case 1: // 添加
				break;
			case 2: // 显示
				break;
			case 3: // 删除
				break;
			case 4: // 修改
				break;
			case 5: // 查找
				break;
			case 6: // 排序 
				break;
			case 7: // 清空
				break;
			default:
				system("clear");
				break;
		}
		p.Show_Menu();
		cin >> chios;
	}
	return 0;
}
