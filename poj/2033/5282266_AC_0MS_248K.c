#include<stdio.h>
#include<string.h>
#define MAX 5000

char str[MAX];
__int64 dp[MAX];

int main()
{
	while(scanf("%s",str)!=EOF){
		int i,len,temp;
		if(strcmp("0",str)==0)
			break;
		len=strlen(str);
		dp[0]=1;
		temp=(str[0]-'0')*10+str[1]-'0';
		if(temp>0&&temp<=26&&str[1]!='0')
			dp[1]=2;
		else
			dp[1]=1;
		for(i=2;i<len;i++){
			temp=(str[i-1]-'0')*10+str[i]-'0';
			if(str[i]=='0')
				dp[i]=dp[i-2];
			else if(temp>0&&temp<=26&&str[i-1]!='0')
				dp[i]=dp[i-2]+dp[i-1];
			else
				dp[i]=dp[i-1];
		}
		printf("%I64d\n",dp[i-1]);
	}
	return 0;
}