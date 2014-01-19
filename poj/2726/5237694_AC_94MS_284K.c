#include<stdio.h>
#include<stdlib.h>
#define MAX 10001

struct node{
	int d,c;
}nodes[MAX];
int n;

int cmp(const void *e1,const void *e2)
{
	struct node *p1,*p2;
	p1=(struct node *)e1;
	p2=(struct node *)e2;
	if(p1->d==p2->d)
		return p1->c-p2->c;
	return p1->d-p2->d;
}

int main()
{
	while(scanf("%d",&n),n){
		int i,ans=0,tmin,temp;
		for(i=0;i<n;i++)
			scanf("%d%d",&nodes[i].d,&nodes[i].c);
		qsort(nodes,n,sizeof(nodes[0]),cmp);
		ans=1;
		tmin=nodes[0].c;temp=nodes[0].d;
		for(i=1;i<n;i++){
			if(nodes[i].c>=tmin)
				continue;
			tmin=nodes[i].c;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}