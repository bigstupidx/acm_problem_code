#include<stdio.h>
#define MAX 2001

struct bug{
	int par;
	int kind;
}bugs[MAX];

int find(int x)
{
	int t=bugs[x].par;
	if(t<0)
		return x;
	bugs[x].par=find(t);
	bugs[x].kind=(bugs[x].kind+bugs[t].kind)%2;
	return bugs[x].par;
}
int main()
{
	int t,ii;
	scanf("%d",&t);
	for(ii=1;ii<=t;ii++)
	{
		int num,inter;
		int i,flag=0;
		scanf("%d%d",&num,&inter);
		for(i=1;i<=num;i++)
			bugs[i].par=-1,bugs[i].kind=0;
		for(i=0;i<inter;i++)
		{
			int u,v,j,k;
			scanf("%d%d",&u,&v);
			if(flag)continue;
			j=find(u);
			k=find(v);
			if(j==k){
				if(bugs[u].kind==bugs[v].kind)
				flag=1;
			}
			else{
				bugs[j].par=k;
				bugs[j].kind=(1+bugs[u].kind+bugs[v].kind)%2;
			}
		}
		printf("Scenario #%d:\n",ii);
		if(flag)
			printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");
	}
	return 0;
}