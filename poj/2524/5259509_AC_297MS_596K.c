#include<stdio.h>
#include<stdlib.h>
#define MAX 50001

int stu[MAX];
int rank[MAX];

int find(int x)
{
	if(x==stu[x])
		return x;
	return stu[x]=find(stu[x]);
}
int cmp(const void *e1,const void *e2)
{
	return *(int *)e1-*(int *)e2;
}
int main()
{
	int n,m,t=0;
	while(scanf("%d%d",&n,&m),n||m)
	{
		int i,j,k,u,v,ans=n;
		for(i=1;i<=n;i++){
			stu[i]=i;
			rank[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			j=find(u);
			k=find(v);
			if(k==j)continue;
		    if(rank[j]>rank[k]) stu[k]=j;
			else
			{
				stu[j]=k;
				if(rank[j]==rank[k])
					rank[k]++;
			}
			ans--;
		}
		printf("Case %d: %d\n",++t,ans);
	}
	return 0;
}