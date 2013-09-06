#include<stdio.h>
#include<stdlib.h>

#define MAX 1001
int arrey[MAX];

int cmp(const void *e1,const void *e2)
{
	return *(int *)e1-*(int *)e2;
}

int XOR(int n)
{
	int i;
	int ans=arrey[0];
	for(i=2;i<=n;i+=2)
		ans=ans^arrey[i];
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,n;
		int temp;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",arrey+i);
		qsort(arrey,n,sizeof(int),cmp);
		arrey[0]=0;
		for(i=1;i<=n;i++)
			arrey[i-1]=arrey[i]-arrey[i-1];
		if(XOR(n))
			printf("Georgia will win\n");
		else
			printf("Bob will win\n");
	}
	return 0;
}
