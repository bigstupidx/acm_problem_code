#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 1000001

int flag[MAX];

void pre_done()
{
	int i;
	memset(flag,1,sizeof(flag));
	flag[2]=flag[3]=1;
	for(i=2;i<=sqrt(MAX);i++)
	{
		int j;
		for(j=1;i*j<=MAX;j++)
			flag[i*j]=0;
	}
	return ;
}

int main()
{
	int n;
	pre_done();
	while(scanf("%d",&n),n)
	{
		int i;
		for(i=2;i<=n/2;i++)
			if(flag[i]&&flag[n-i])break;
		printf("%d = %d + %d\n",n,i,n-i);
	}
	return 0;
}
