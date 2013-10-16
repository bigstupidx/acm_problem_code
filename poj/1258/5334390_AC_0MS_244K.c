#include<stdio.h>
int n;
int matrix[102][102];
int closed[102];
int prim()
{
	int i,j,k,min,ans=0;
	for(i=0;i<n;i++)
		closed[i]=matrix[0][i];
	for(j=0;j<n-1;j++)
	{
		min=1000000;
		for(i=0;i<n;i++)
			if(closed[i]&&min>closed[i]){
				k=i;min=closed[i];
			}
		ans+=min;
		closed[k]=0;
		for(i=0;i<n;i++)
			if(closed[i]&&matrix[k][i]<closed[i])
				closed[i]=matrix[k][i];
	}
	return ans;
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",matrix[i]+j);
		printf("%d\n",prim());
	}
	return 0;
}