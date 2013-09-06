#include<stdio.h>
#define MAX 50001
int query[MAX],n;
__int64 sum;

__int64 maxquery(int i,int j)
{
	__int64 temp=0,su=0;
	int k;
	for(k=i;k<=j;k++)
	{
		temp+=query[k];
		if(temp>su)
			su=temp;
		else if(temp<0)
			temp=0;
	}
	return su;
}
void solve()
{
	int k;
	__int64 sum1=0,sum2=0;
	for(k=2;k<=n-1;k++){
		sum1=maxquery(1,k);
		sum2=maxquery(k+1,n);
		if(sum1+sum2>sum)
			sum=sum1+sum2;
	}
	return ;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int i;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&query[i]);
		solve();
		printf("%I64d\n",sum);
	}
	return 0;
}