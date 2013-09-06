#include<stdio.h>
#include<string.h>
#define MAX 200
int matrix[55][55];
int closed[55];
int n;

int prim()
{
	int i,j,k,min,ans=0;
	for(i=1;i<=n;i++)
		closed[i]=matrix[1][i];
	closed[1]=0;
	for(i=0;i<n-1;i++)
	{
		min=MAX;
		for(j=1;j<=n;j++)
			if(closed[j]&&min>closed[j]){
				k=j;min=closed[j];
			}
		ans+=min;
		closed[k]=0;
		for(j=1;j<=n;j++)
			if(closed[j]&&matrix[k][j]<closed[j])
				closed[j]=matrix[k][j];
	}
	return ans;
}
int main()
{
	while(scanf("%d",&n),n){
		int i,j,k,t,temp;
		scanf("%d",&t);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				matrix[i][j]=MAX;
		for(k=0;k<t;k++){
			scanf("%d%d%d",&i,&j,&temp);
			if(matrix[i][j]>temp)
				matrix[i][j]=matrix[j][i]=temp;
		}
		if(n==1)printf("0\n");
		else
			printf("%d\n",prim());
	}
	return 0;	
}