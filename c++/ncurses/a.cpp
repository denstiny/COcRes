#include <clocale>
#include<iostream>
#include<locale>
#include <ncurses.h>
using namespace std;

int main(int argc,char *argv[]) {
	setlocale(LC_ALL,"");

	initscr(); // 进入 ncurses 模式


	int a = 0;
	int s = 0;
	noecho();  // 关闭回显
	cbreak();  // 开启输入直接发送到程序

	move(0, 43);
	printw("MUSIC");

	move(2, 1);
	printw("LIST");
	while(a < 16) {
		a++;
		s++;
		move(s, 8);
		printw("|");
	}
	a = 8;
	while (a < 90) {
		move(17, a++);
		printw("-");
	}
	a = 10;
	move(18, 4);
	printw("告白气球");



	while(a < 20) {
		s = getch();
		printw("%c",s);
		move(2, a);
		a++;
		printw("%d",s);
		move(1, a);
	refresh();  // 将虚拟终端内容发送到 终端
	}
	refresh();  // 将虚拟终端内容发送到 终端
	endwin();  //  退出 ncurses
	
	return 0;
}
