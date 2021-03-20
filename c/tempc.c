#include<stdio.h>
#include<stdlib.h>
struct Book
{
    char title[128];
    char author[40];
    struct Book *next;
};
void getInput(struct Book *book)
{
    printf("请输入书名:");
    scanf("%s",book->title);  
	while (getchar() != '\n') {
		continue;
	}
    printf("请输入作者:");
    scanf("%s",book->author);
	while (getchar() != '\n') {
		continue;
	}
}
void addBook(struct Book **library)
{
    struct Book *book,*temp;
    book=(struct Book *)malloc(sizeof(struct Book));
    if(book==NULL)
    {
        printf("内存分配失败了！\n");
        exit(1);
    }
    getInput(book);
    if(*library!=NULL)
    {
            temp=*library;
            *library=book;
            book->next=temp;
    }
    else
    {
        *library=book;
        book->next=NULL;
    }
}
void printLibrary(struct Book *library)
{
    struct Book *book;
    int count=1;

    book=library;
    while(book!=NULL)
    {
        printf("book:%d\n",count);
        printf("书名：%s\n",book->title);
        printf("作者：%s\n",book->author);
        book=book->next;
        count++;
    }
}
void releaseLibrary(struct Book **library)
{
    struct Book *temp;
    while(*library!=NULL)
    {
        temp=*library;
        *library=(*library)->next;
        free(temp);
    }

}
void initBook(struct Book * v) {
	*v->author = '\0';
	v->next = NULL;
	*v->title = '\0';
}

int main(int argc, char const *argv[])
{
    struct Book *library;
    int ch;
    while(1)
    {
        printf("是否需要录入书籍信息(Y/N):");
        do
        {
            ch=getchar();
        }while(ch!='Y' && ch!='N');
        if(ch=='Y')
        {
            addBook(&library);
        }
        else
        {
            break;
        }
    }
    printf("请问是否需要打印图书信息(Y/N):");
        do
        {
            ch=getchar();
        }while(ch!='Y'&& ch!='N');
        if(ch=='Y')
        {
            printLibrary(library);
        }
        releaseLibrary(&library);
    return 0;
}

