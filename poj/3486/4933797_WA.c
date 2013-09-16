#include<stdio.h>
#include<stdlib.h>
#define MAX 1010

int m[MAX][MAX],cost[MAX][MAX];
int c,n;
void solve()
{
	int i,j,k,temp;
	for(i=2;i<=n;i++)
		for(j=i;j<=n;j++)
			if(j==i){
				cost[i][j]=c+m[i][j]+cost[1][j-1];//运用dp
				for(k=2;k<i;k++)
					if( (c+m[i][j]+cost[k][j-1]) < cost[i][j] )
						cost[i][j]=c+m[i][j]+cost[k][j-1];
			}
			else
				cost[i][j]=cost[i][j-1]+m[i][j];
	temp=cost[1][n];
	for(i=2;i<=n;i++)
		if(cost[i][n]<temp)
			temp=cost[i][n];
	printf("%d\n",temp);
	return ;
}

int main()
{
	while(scanf("%d",&c)!=EOF){
		int i,j;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			for(j=i;j<=n;j++)
				scanf("%d",&m[i][j]);
		memset(cost,0,sizeof(cost));
		for(i=1;i<=n;i++)
			cost[1][i]=m[1][i]+c;
		for(i=2;i<=n;i++)
			for(j=i;j<=n;j++){
				if(i==j)
					continue;
				else
					m[i][j]=m[i][j]-m[i][j-1];
			}
		solve();
	}
	system("pause");
	return 0; 
}
