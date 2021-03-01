#include<iostream>
using namespace std;
const int Len = 66;
const int Divs = 6;
void subdivide(char ar[],int low,int hight,int level);
int main(int argc,char *argv[])
{
	char ruler[Len];
	int i ;
	for(i = 1;i < Len -2 ;i++)
		ruler[i] = ' ';
	ruler[Len - 1] = '\0';
	int max = 0;
	int min = 0;
	for(int i  = 0; i < Divs;i++)
	{
		subdivide(ruler, min, max, i);
		cout << ruler << endl;
		for (int j = 1; j < Len -2 ; j++) {
			ruler[j] = ' ';
		}
	}
	return 0;
}
void subdivide(char ar[],int low,int hight,int level)
{

}
