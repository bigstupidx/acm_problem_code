#include<stdio.h>
#include<string.h>

char str[100];
struct Str{
	char x;
	char y;
}ss[50];

int solve()
{
	int len,i,j,k;
	len=strlen(str);
	for(i=1;i<len;i++)
		for(j=0;j<len-i;j++)
		{
			for(k=0;k<j;k++)
				if(str[j]==ss[k].x&&str[j+i]==ss[k].y)
					return 1;
			ss[j].x=str[j];
			ss[j].y=str[j+i];
		}
	return 0;
}
int main()
{
	while(scanf("%s",str),strcmp("*",str))
	{
		if(solve())
			printf("%s is NOT surprising.\n",str);
		else
			printf("%s is surprising.\n",str);
	}
	return 0;
}
