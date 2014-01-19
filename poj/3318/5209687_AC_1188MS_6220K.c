/*
随机算法，但是不是随机，很巧妙
用{1，2，3，4，……，n}来乘两边
*/

#include<stdio.h>
#include<string.h>
#define MAX 510

__int64 a[MAX][MAX];
__int64 b[MAX][MAX];
__int64 c[MAX][MAX];

__int64 temp[MAX];
__int64 ans[MAX];
__int64 ANS[MAX];

int n;
void solve()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			temp[i]+=a[j][i]*(j+1);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			ANS[i]+=temp[j]*b[j][i];
	for(i=0;i<n;i++)
		if(ANS[i]!=ans[i]){
			printf("NO\n");
			return ;
		}
	printf("YES\n");
	return ;
}

int main()
{
	while(scanf("%d",&n)!=EOF){
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%I64d",a[i]+j);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%I64d",b[i]+j);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%I64d",c[i]+j);

		memset(temp,0,sizeof(temp));
		memset(ans,0,sizeof(ans));
		memset(ANS,0,sizeof(ANS));

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				ans[i]+=c[j][i]*(j+1);
		solve();
	}
	return 0;
}
