
#include<stdio.h>
int arrey[21][21];
int arr[21];
int main()
{
	int n,s;
	while(scanf("%d%d",&n,&s)==2){
		int i,j;
		arr[0]=0;
		for(i=1;i<=n;i++)
			arr[i]=arr[i-1]+i;
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++)
				arrey[j][i]=(s+arr[i-1]+j-2)%9+1;
		for(i=1;i<=n;i++){
			for(j=1;j<i;j++)
				printf("  ");
			for(;j<=n;j++)
				printf("%d ",arrey[i][j]);
			printf("\n");
		}
	}
	return 0;
}