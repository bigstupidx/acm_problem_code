#include<stdio.h>
#include<string.h>
#define MAX 3404

int c[MAX][13000];
int w[MAX],p[MAX];
int n,m;
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		int i,j;
		for(i=1;i<=n;i++)
			scanf("%d%d",w+i,p+i);
		for(i=0;i<=n;i++)
			for(j=0;j<=m;j++)
				c[i][j]=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
				if(w[i]<=j){
					if(p[i]+c[i-1][j-w[i]]>c[i-1][j])
						c[i][j]=p[i]+c[i-1][j-w[i]];
					else
						c[i][j]=c[i-1][j];
				}
				else
					c[i][j]=c[i-1][j];
			}
		printf("%d\n",c[n][m]);
	}
	return 0;
}