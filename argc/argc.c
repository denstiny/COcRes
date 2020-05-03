#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int a,s = 0,d;
	char str[argc];
	for(a = 1;a<argc-1;a++)
	{
		
		for(d = 0;;a++)
		{

			
			if(argv[a]+d != NULL)
			{
				str[s] = *(argv[a]);
			}
		}
		//strcpy(str[s],*argv[a]);
		
	}
	puts(str);

	
	return 0;
}

