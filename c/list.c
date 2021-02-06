#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)
#define num 30
typedef struct _mvname
{
	char name[num];//电影名
	int number;//电影评分（0-9）
	struct _mvname* next;
}new;

void char_new(struct _mvname* sb);//微软我知道你看着我呢，这个插入链表如果不成功，你全家没鸟

void print(struct _mvname* fp);//遍历链表函数

char* _scanf(char* fi, int nume);//前入函数，效果一般

void char_new1(struct _mvname* _sb,struct _mvname* sb);//后入链表，爽

void char_new2(struct _mvname* sb);//查找内存地址

void char_new3(struct _mvname* sb);//无限中出

void char_new4(new* sb, new* sb1);//删除节点

void char_new5(new* sb, new* sb1);//清楚所有内存
/*
				  _
				 / \
				/   \
				|   |
				|   |
				|   |
				|   |
				|   |																														
				|   |
				|   |
				|   |
				|   |
			   \__|   |__/
		     //////|_______|\\\\\\\
*/
//void new_glen(int a);//功能选择模块（switch）

int main()
{
	int a;
	char input[num];
	new* head = NULL, * last = NULL, * prev = NULL;
	puts("stdin the name");
	while (_scanf(input, num) != NULL && input[0] != '\0')
	{
		prev = (struct _mvname*)malloc(sizeof(struct _mvname));
		if (prev == NULL)
			puts("prev分配内存失败");
		if (head == NULL)
		{
			head = prev;
		}
		else last->next = prev;
		last = prev;
		prev->next = NULL;
		strcpy(prev->name, input);
		puts("stdin the number(0-9)");
		scanf_s("%d", &prev->number);
		while (getchar() != '\n') {
			continue;
		}
		puts("stdion the name(no stdion Enter)");
	}
	prev = head;
	print(prev);
	puts("正在传入节点的地址		........");
	printf("1: 头结点插入\n2:尾结点插入\n3:查找节点\n");
	scanf_s("%d", &a);
	while (getchar() != '\n') continue;
	switch (a)
	{
	case 1:char_new(prev); break;
	case 2:char_new1(prev,last);//链表尾插入
		break;
	case 3:char_new2(prev); break;
	default:
		break;
	}
	
}
void print(struct _mvname* fp)
{
	while (fp != NULL)
	{
		printf("TV zhe name :%s\t\tnuber zhe is:%d\n", fp->name, fp->number);
		fp = fp->next;
	}

}
char* _scanf(char* fp, int a)
{
	char* re = NULL, * find = NULL;
	re = fgets(fp, a, stdin);
	if (re)
	{
		find = strchr(fp, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
			{
				continue;
			}
	}
	return find;
}
void char_new(struct _mvname* sb)//传输头结点的地址
{
	struct _mvname* _2b=NULL, * _3b=NULL,*_4b=NULL; char input[num];
	puts("stdin the name");
	while (_scanf(input, num) != NULL && input[0] != '\0')
	{
		_3b = (struct _mvname*)malloc(sizeof(struct _mvname));
		if (_3b == NULL) puts("插入链表失败");
		if (_2b==NULL)
		{
			_2b=_3b;//头结点的下一个节点修改为_3b
		}
		else _4b->next = _3b;
		_3b->next = NULL;
		_4b = _3b;
		strcpy(_3b->name, input);
		puts("stdin the number(0-9)");
		scanf_s("%d", &_3b->number);
		while (getchar()!='\n')
		{
			continue;
		}
		puts("stdion the name(no stdion Enter)");
		
	}
	_3b = _2b;
	_4b->next = sb;
	print(_3b);
}
void char_new1(struct _mvname*_sb,struct _mvname* sb)
{
	struct _mvname* _1sb=NULL,*_2sb=NULL,*_3sb=NULL;
	char input[num];
	puts("stdin the name");

	while (_scanf(input, num) != NULL && input[0] != '\0')
	{	_1sb = (struct _mvname*)malloc(sizeof(struct _mvname));
		if (_3sb == NULL)
		{
			_3sb = _1sb;
		}
		else _2sb->next= _1sb;
		_1sb->next = NULL;
		_2sb = _1sb;
		if (_1sb == NULL)
		{
			puts("NO malloc!");
		}
		strcpy(_1sb->name, input);
		puts("stdin the number(0-9)");
		scanf_s("%d", &_1sb->number);
		while (getchar()!='\n')
		{
			continue;
		}
		puts("stdion the name(no stdion Enter)");
	}
	
	_1sb = _3sb;
	sb->next = _1sb;
	print(_sb);
}
void char_new2(struct _mvname* sb)// 查找地址
{
	struct _mvname* fp = NULL,*fp1=NULL,*fp2=NULL;
	fp1 = sb;
	int a, nuber;
	char input[num];
	printf("查找的电影名(1)或序号(2)");
	scanf_s("%d", &a);
	while (getchar() != '\n') continue;
	switch (a)
	{
	case 1:
		_scanf(input, num) != NULL && input[0] != '\0';
		while (sb != NULL)
		{

			fp = sb;
			if (input == sb->name)
			{
				puts("找到了，地址已经保存"); break;
			}
			fp2 = sb;
			sb = sb->next;
		}
		puts("没有找到");
		break;
	case 2:scanf_s("%d", &nuber);
		while (sb != NULL)
		{

			fp = sb;
			if (nuber == sb->number)
			{
				puts("找到了，地址已经保存"); break;
			}
			fp2 = sb;
			sb = sb->next;
		}

		break;
	default:
		break;
	}//fp保存插入节点位置
	puts("1：插入");
	puts("2：删除");
	scanf_s("%d", &a);
	while (getchar() != '\n') continue;
	switch (a)
	{
	case 1:char_new3(fp1, fp); break;
	case 2:char_new4(fp1, fp,fp2); break;
	default:
		break;
	}
}
void char_new3(new *_sb,struct _mvname* sb)
{
	new* p1 = NULL, * p2 = NULL,*p3=NULL;
	char input[num];
	while (getchar() != '\n') continue;
	puts("stdin TV zhe name(no zhe stdin Enter!)");
	while (_scanf(input, num) != NULL && input[0] != '\0')
	{
		p1 = (new*)malloc(sizeof(new));
		if (p1) puts("malloc zhe ok!");
		if (p2 == NULL)
		{
			p2 = p1;
		}
		else
			p3->next = p1;
		p3 = p1;
		p1->next = NULL;
		strcpy(p1->name, input);
		puts("stdin zhe 0-9");
		scanf_s("%d", &p1->number);
		while (getchar() != '\n')
		{
			continue;
		}
		puts("stdin TV zhe name(no zhe stdin Enter!)");
	}
	p1 = p2;
	p2 = sb->next;
	sb->next = p1;
	p1->next = p2;
	print(_sb);
}
void char_new4(new* sb, new* sb1,new *sb4)//sb=head	sb1=找到的节点位置
	 Conflicting types for 'char_new4'
	 [clang: conflicting_types]

{
	//new* sb2 = NULL, * sb3 = NULL;
	
	sb4->next = sb1->next;
	free(sb1);
	print(sb);
}
