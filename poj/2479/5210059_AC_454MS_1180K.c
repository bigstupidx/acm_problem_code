#include<stdio.h>
#define MAX 50002
int query[MAX],n;
__int64 sum;
__int64 sum1[MAX],sum2[MAX];

void solve()
{
	int i;
	__int64 temp1,temp2;
	temp1=sum1[1]=query[1];
	temp2=sum2[n]=query[n];
	if(temp1<0)temp1=0;
	if(temp2<0)temp2=0;
	for(i=2;i<=n;i++){
		temp1+=query[i];
		sum1[i]=sum1[i-1];
		if(temp1>sum1[i-1])
			sum1[i]=temp1;
		else if(temp1<=0)
			temp1=0;

		temp2+=query[n-i+1];
		sum2[n-i+1]=sum2[n-i+2];
		if(temp2>sum2[n-i+2])
			sum2[n-i+1]=temp2;
		else if(temp2<=0)
			temp2=0;
	}
	sum=sum1[1]+sum2[2];
	for(i=2;i<n;i++){
		temp1=sum1[i]+sum2[i+1];
		if(temp1>sum)
			sum=temp1;
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