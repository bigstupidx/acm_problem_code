#include<stdio.h>

int n,m;
int arrey[2][60];

void solve()
{
	int i,j,k,t,p,now=0,c;
	for(i=1;i<=n;i++)
		arrey[0][i]=i;
	for(t=0;t<m;t++){
		now=1-now;
		scanf("%d%d",&p,&c);
		for(i=1;i<=n-p-c+1;i++)
			arrey[now][i]=arrey[1-now][i];
		for(;i<=n-c;i++)
			arrey[now][i]=arrey[1-now][i+c];
		for(;i<=n;i++)
			arrey[now][i]=arrey[1-now][i-p+1];
	}
	printf("%d\n",arrey[now][n]);
}
int main()
{
	while(scanf("%d%d",&n,&m),m||n){
		solve();
	}
	return 0;
}