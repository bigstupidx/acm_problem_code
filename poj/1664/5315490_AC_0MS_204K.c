#include<stdio.h>
#include<string.h>
#define MAX 50
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
			arrey[now][j]=arrey[1-now][j]+temp;
		}
	}
	return arrey[now][n];
}

int main()
{
	int m,n;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(arrey,0,sizeof(arrey));
		printf("%d\n",dp(n,m));
	}
	return 0;
}