#include<stdio.h>
#include<stdlib.h>
int arrey[360][360];
int sum[360][360];
int main()
{
	int r,c,n,max;
	scanf("%d",&n);
	for(r=1;r<=n;r++){
		for(c=1;c<=r;c++)
			scanf("%d",&arrey[r][c]);
	}
	for(r=n-1;r>=1;r--)
		for(c=1;c<=r;c++)
			arrey[r][c]+=arrey[r+1][c]>arrey[r+1][c+1]?arrey[r+1][c]:arrey[r+1][c+1];
	printf("%d\n",arrey[1][1]);
	system("pause");
	return 0;
}