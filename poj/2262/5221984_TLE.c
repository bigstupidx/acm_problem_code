#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 1000001

int flag[MAX];

int isprime(int n)
{
	int i,temp;
	temp=sqrt(n);
	for(i=2;i<=temp;i++)
		if(!(n%i))
			break;
	if(i>temp)
		return 1;
	return 0;
}
void pre_done()
{
	int i;
	memset(flag,0,sizeof(flag));
	flag[2]=flag[3]=1;
	for(i=3;i<MAX;i++)
		if(isprime(i))
			flag[i]=1;
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
