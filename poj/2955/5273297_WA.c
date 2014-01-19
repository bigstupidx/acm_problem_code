#include<stdio.h>
#include<string.h>
#define MAX 200

int dp[MAX][MAX];
char str[MAX];

int judge(int i,int j)
{
	if(str[i]=='('&&str[j]==')')
		return 1;
	if(str[i]=='['&&str[j]==']')
		return 1;
	return 0;
}
int main()
{
	while(gets(str)){
		int len,i,k,ans=0,step,temp;
		if(!strcmp(str,"end"))
			break;
		len=strlen(str);
		memset(dp,0,sizeof(dp));
		for(i=0;i<len-1;i++)
			if(judge(i,i+1))
				dp[i][i+1]=1;
		for(step=2;step<len;step++)
			for(i=0;i<len-step;i++){
				if(judge(i,i+step))
					dp[i][i+step]=dp[i+1][i+step-1]+1;
				for(k=i+1;k<i+step;k++){
					temp=dp[i][k]+dp[k+1][i+step];
					if(temp>dp[i][i+step])
						dp[i][i+step]=temp;
				}
		}
		printf("%d\n",dp[0][len-1]*2);
	}
	return 0;
}