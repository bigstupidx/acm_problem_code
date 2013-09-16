#include<stdio.h>
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	__int64 ans,n;
	while(scanf("%I64d",&n)!=EOF){
		__int64 i;
		ans=0;
		for(i=1;i<=n;i++)
			ans+=gcd(i,n);
		printf("%I64d\n",ans);
	}
	return 0;
}
