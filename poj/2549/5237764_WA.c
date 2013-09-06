#include<stdio.h>
#include<stdlib.h>
#define MAX 1001

int arrey[MAX];
int n;

int cmp(const void *e1,const void *e2)
{
	return *(int *)e1-*(int *)e2;
}

int find(int i,int j,int k)
{
	int sum=arrey[i]+arrey[j]+arrey[k];
	int m;
	for(m=i+1;m<n;m++){
		if(arrey[m]>sum)
			return 0;
		if(arrey[m]==sum){
			printf("%d\n",sum);
			return 1;
		}
	}
	return 0;
}
int main()
{
	while(scanf("%d",&n)!=EOF&&n){

		int i,j,k;
		if(n<4){
			printf("no solution\n");
			continue;
		}
		for(i=0;i<n;i++)
			scanf("%d",arrey+i);
		qsort(arrey,n,sizeof(int),cmp);
		for(i=n-2;i>=2;i--)
			for(j=i-1;j>=1;j--)
				for(k=j-1;k>=0;k--)
					if(find(i,j,k))
						goto xx;
		printf("no solution\n");
xx:continue;
	}
	return 0;
}