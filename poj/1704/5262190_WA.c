#include<stdio.h>
#include<stdlib.h>

#define MAX 1001
int arrey[MAX];

int cmp(const void *e1,const void *e2)
{
	return *(int *)e1-*(int *)e2;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,n;
		int temp,ans;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",arrey+i);
		qsort(arrey,n,sizeof(int),cmp);
		if(n%2){
			ans=arrey[1];
			for(i=2;i<=(n+1)/2;i++)
				ans^=(arrey[2*i-1]-arrey[2*i-2]);
		}
		else{
			ans=arrey[2]-arrey[1];
			for(i=2;i<=n/2;i++)
				ans^=(arrey[2*i]-arrey[2*i-1]);
		}
		if(ans)
			printf("Georgia will win\n");
		else
			printf("Bob will win\n");
	}
	return 0;
}
