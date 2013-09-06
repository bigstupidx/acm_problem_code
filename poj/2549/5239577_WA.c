#include<stdio.h>
#include<stdlib.h>
#define MAX 1001

int arrey[MAX];
int n;

int cmp(const void *e1,const void *e2)
{
	return *(int *)e1-*(int *)e2;
}

int find(int low,int high,int x)
{
	int middle;
	while(low<high){
		middle=(low+high)/2;
		if(arrey[middle]==x)
			return 1;
		if(arrey[middle]<x)
			low=middle+1;
		else
			high=middle-1;
	}
	return 0;
}
int main()
{
	while(scanf("%d",&n),n)
	{
		int i,j,k;
		for(i=1;i<=n;i++)
			scanf("%d",arrey+i);
		qsort(arrey+1,n,sizeof(int),cmp);
		if(n<4){
			printf("no solution\n");
			continue;
		}
		for(i=n;i>=1;i--)
			for(j=n;j>=1;j--){
				if(arrey[i]<arrey[j]+arrey[1]+arrey[2])
					continue;
				if(i!=j){
					for(k=1;k<=j-2;k++)
						if(k!=i){
							if(find(k+1,j-1,arrey[i]-arrey[k]-arrey[j]))
								goto loop;
						}
				}
			}
		printf("no solution\n");
		continue;
        loop:printf("%d\n",arrey[i]);
	}
	return 0;
}
