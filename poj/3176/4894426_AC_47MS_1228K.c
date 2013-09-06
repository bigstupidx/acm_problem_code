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
		sum[r][0]=0;
	}
	sum[1][1]=arrey[1][1];
	for(r=1;r<=n;r++)
		for(c=1;c<=r;c++)
			sum[r][c]=arrey[r][c]+(sum[r-1][c]>sum[r-1][c-1]?sum[r-1][c]:sum[r-1][c-1]);
	max=sum[n][1];
	for(c=1;c<=n;c++)
		if(sum[n][c]>max)
			max=sum[n][c];
	printf("%d\n",max);
	system("pause");
	return 0;
}