/*

题目意思为：给定一个数N，构造一个互不相等的数列N1,N2,N3,……Nn；
约束条件
（1）：N1+N2+N3+……+Nn=N；
（2）：N1*N2*N3*……*Nn最大（组合原理）
从2开始构造
*/

#include<stdio.h>
int ans[1000];
int n;

void solve()
{
	int i=1,t=2,sum=2;
	int len;
	ans[0]=2;
	while(n-sum>t){
		t++;
		sum+=t;
		ans[i++]=t;
	}
	len=i;
	if(n-sum==t){
		for(i=0;i<len-1;i++)
			printf("%d ",ans[i]+1);
		printf("%d\n",ans[i]+2);
		return ;
	}
	else{
		int temp=n-sum;
		for(i=len-1;i>=0&&temp;i--)
			ans[i]+=1,temp--;
		for(i=0;i<len-1;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[i]);
		return ;
	}
	return ;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
		solve();
	return 0;
}