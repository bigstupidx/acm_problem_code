#include<stdio.h>
#define MAX 510
#define HIGH_VALUE 100000
int matrix[MAX][MAX],closed[MAX];
int n;

int prim()
{
	int ans=0,i,k,temp=HIGH_VALUE;
	for(i=0;i<n;i++){
		closed[i]=matrix[0][i];
		if(closed[i]){
			if(temp>closed[i]){
				temp=closed[i];k=i;
			}
		}
	}
	if(ans<temp)ans=temp;
	closed[k]=0;
	for(i=0;i<n;i++){
		if(closed[i]){
			if(closed[i]>matrix[k][i])
				closed[i]=matrix[k][i];
		}
	}
	for(i=1;i<n-1;i++)
	{
		temp=HIGH_VALUE;
		for(i=0;i<n;i++){
			if(closed[i])
			{
				if(temp>closed[i])
					temp=closed[i];k=i;
			}
		}
		if(ans<temp)ans=temp;
		closed[k]=0;
		for(i=0;i<n;i++){
			if(closed[i]){
				if(closed[i]>matrix[k][i])
					closed[i]=matrix[k][i];
			}
		}
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int i,j;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&matrix[i][j]);
		printf("%d\n",prim());
	}
	return 0;
}