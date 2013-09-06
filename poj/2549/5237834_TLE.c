#include<stdio.h>
#include<stdlib.h>
#define MAX 1001

int arrey[MAX];
int n,max;

int cmp(const void *e1,const void *e2)
{
	return *(int *)e1-*(int *)e2;
}

int find(int i,int j,int k)
{
	int m,sum;
	sum=arrey[i]+arrey[j]+arrey[k];
	if(sum<=max)
		return 0;
	if(arrey[i]==arrey[j]||arrey[i]==arrey[k]||arrey[j]==arrey[k])
		return 0;
	for(m=i+1;m<n;m++){
		if(arrey[m]>sum)
			return 0;
		if(arrey[m]==sum){
			if(sum>max)
				max=sum;
			return 1;
		}
	}
	return 0;
}
int main()
{
	while(scanf("%d",&n)!=EOF&&n){

		int i,j,k,flag=0;
		if(n<4){
			printf("no solution\n");
			continue;
		}
		max=-536870912*3;
		for(i=0;i<n;i++)
			scanf("%d",arrey+i);
		qsort(arrey,n,sizeof(int),cmp);
		for(i=n-2;i>=2;i--){
			if(flag&&(arrey[i]+arrey[i-1]+arrey[i-2]<max))
				break;
			for(j=i-1;j>=1;j--){
				if(flag&&(arrey[i]+arrey[j]+arrey[j-1]<max))
					break;
				for(k=j-1;k>=0;k--){
					if(find(i,j,k)){
						flag=1;break;
					}
				}
			}
		}
		if(!flag){
			printf("no solution\n");
			continue;
		}
        xx:printf("%d\n",max);
	}
	return 0;
}