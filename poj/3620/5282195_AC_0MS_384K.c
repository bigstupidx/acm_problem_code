#include<stdio.h>
#define	MAX 101
int matrix[MAX][MAX];
int n,m,k;
int search(int i,int j)
{
	if(!matrix[i][j])return 0;
	if(i<1||i>n||j<1||j>m)
		return 0;
	matrix[i][j]=0;
	return 1+search(i-1,j)+search(i+1,j)+search(i,j-1)+search(i,j+1);
}
int main()
{
	
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		int i,j,temp,ans=0;
		int x,y;
		for(i=0;i<=n;i++)
			for(j=0;j<=m;j++)
				matrix[i][j]=0;
		for(i=0;i<k;i++){
			scanf("%d%d",&x,&y);
			matrix[x][y]=1;
		}
		for(i=0;i<=n;i++)
			for(j=0;j<=m;j++)
				if(matrix[i][j]){
					temp=search(i,j);
					if(temp>ans)ans=temp;
				}
		printf("%d\n",ans);
	}
	return 0;
}