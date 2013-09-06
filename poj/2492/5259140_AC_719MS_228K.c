#include<stdio.h>
#define MAX 2001

struct bug{
	int par;
	int kind;
}bugs[MAX];

int find(int x)
{
	int t=bugs[x].par;
	if(t==x)
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
		int n,i,j,inter,u,v;
		int flag=0;
		scanf("%d%d",&n,&inter);
		for(i=1;i<=n;i++)
		{
			bugs[i].par=i;
			bugs[i].kind=0;
		}
		while(inter--){
			scanf("%d%d",&u,&v);
			if(flag)continue;
			i=find(u);
			j=find(v);
			if(i==j){
				if(bugs[u].kind==bugs[v].kind)
					flag=1;
			}
			else{
				bugs[i].par=j;
				bugs[i].kind=(1+bugs[u].kind+bugs[v].kind)%2;
			}
		}
		printf("Scenario #%d:\n",ii);
		if(flag)
			printf("Suspicious bugs found!\n\n");
		else
			printf("No suspicious bugs found!\n\n");
	}
	return 0;
}