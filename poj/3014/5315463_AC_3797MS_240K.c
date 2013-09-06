#include<stdio.h>
#define MAX 4505
#define MOD 1000000007
int arrey[2][MAX];

int dp(int n,int m)
{
	int now=0;
	int i,j,temp;
	for(i=1;i<=m;i++){
		now=1-now;
		for(j=1;j<=n;j++){
			if(j<i)temp=0;
			else if(j==i)temp=1;
			else temp=arrey[now][j-i];
			arrey[now][j]=(arrey[1-now][j]+temp)%MOD;
		}
	}
	return arrey[now][n];
}

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	printf("%d\n",dp(n,m));
	return 0;
}