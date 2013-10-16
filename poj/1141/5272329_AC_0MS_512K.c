#include<stdio.h>
#include<string.h>
#define MAX 200

int dp[MAX][MAX],pos[MAX][MAX];
char brack[MAX];

int judge(int i,int j)
{
	if(brack[i]=='('&&brack[j]==')')
		return 1;
	if(brack[i]=='['&&brack[j]==']')
		return 1;
	return 0;
}
void rever(int i,int j)
{
	if(i>j) return ;
	if(i==j){
		if(brack[i]=='('||brack[i]==')')
			printf("()");
		else
			printf("[]");
	}
	else{
		if(pos[i][j]==-1){
			printf("%c",brack[i]);
			rever(i+1,j-1);
			printf("%c",brack[j]);
		}
		else{
			int k=pos[i][j];
			rever(i,k);
			rever(k+1,j);
		}
	}
}
int main()
{
	while(gets(brack)){
		int len,i,j,k,m,temp;
		len=strlen(brack);
		memset(dp,0,sizeof(dp));
		memset(pos,-1,sizeof(pos));
		for(i=0;i<len;i++)
			dp[i][i]=1;
		for(i=1;i<len;i++)
			for(j=0;j<=len-i-1;j++){
				if(judge(j,j+i))
					m=dp[j+1][j+i-1];
				else
					m=100000000;
				for(k=j;k<j+i;k++){
					temp=dp[j][k]+dp[k+1][j+i];
					if(m>temp){
						m=temp;
						pos[j][i+j]=k;
					}
				}
				dp[j][j+i]=m;
			}
		rever(0,len-1);
		printf("\n");
	}
	return 0;
}