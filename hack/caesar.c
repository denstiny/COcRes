#include<stdio.h>
#include<string.h>
int main()
{
	int a,i,b=0;
	char as[] = "oknqdbqmoq{kag_tmhq_xqmdzqp_omqemd_qzodkbfuaz}";
	char st[strlen(as)],m;
	while(b < 26)
	{
		for(i = 0; i < 26;i++)
		{
			 for(i=0; i<strlen(as); i++)
			{
				if(as[i] >= 'A' && as[i] <= 'Z')
				{
					as[i] = ((as[i]-'A')+b)%26+'A';
				}
				else if(as[i] >= 'a' && as[i] <= 'z')
				{
					as[i] = ((as[i]-'a')+b)%26+'a';
				}
			}
		}
		b++;
		printf("偏移量=%d ：%s\n",b,as);
		memset(st,0,strlen(st));
	}
	return 0;
}
