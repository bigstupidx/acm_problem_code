#include<stdio.h>
#include<string.h>

char number[40];
int arrey[35];

int main()
{
	int i;
	for(i=1,arrey[0]=1;i<35;i++)
		arrey[i]=arrey[i-1]*2;
	while(scanf("%s",number),number[0]!='0'){
		int ans=0;
		int j,len;
		len=strlen(number);
		for(i=0;i<len;i++)
			ans+=(number[i]-'0')*(arrey[len-i]-1);

		printf("%d\n",ans);
	}
	return 0;
}
