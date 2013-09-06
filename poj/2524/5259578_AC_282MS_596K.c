#include<stdio.h>
#include<stdlib.h>
#define MAX 50001

int par[MAX];
int rank[MAX];

int find(int x)
{
	if(x==par[x])
		return x;
	return par[x]=find(par[x]);
}

void union_set(int i,int j)
{
	if(rank[i]>rank[j])
		par[j]=i;
	else{
		par[i]=j;
		if(rank[i]==rank[j])
			rank[j]++;
	}
}
int main()
{
	int n,m,t=0;
	while(scanf("%d%d",&n,&m),n||m)
	{
		int i,j,k,u,v,ans=n;
		for(i=1;i<=n;i++){
			par[i]=i;
			rank[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			j=find(u);
			k=find(v);
			if(k==j)continue;
		    union_set(k,j);
			ans--;
		}
		printf("Case %d: %d\n",++t,ans);
	}
	return 0;
}