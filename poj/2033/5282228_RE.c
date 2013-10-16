#include<stdio.h>
#include<string.h>
#define MAX 600

char str[MAX];
int dp[MAX],n;

int main()
{
	while(scanf("%s",str)!=EOF){
		int i,j,len;
		if(strcmp("0",str)==0)
			break;
		len=strlen(str);
		dp[0]=1;
		if(((str[0]-'0')*10+str[1]-'0')<=26)
			dp[1]=2;
		else
			dp[1]=1;
		for(i=2;i<len;i++)
			if(((str[i-1]-'0')*10+str[i]-'0')<=26)
				dp[i]=dp[i-2]+dp[i-1];
			else
				dp[i]=dp[i-1];
		printf("%d\n",dp[i-1]);
	}
	return 0;
}