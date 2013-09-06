#include<stdio.h>
long k,m;
long arrey[10];

void solve()
{
	int i=0;
	long sum=1,temp;
	while(sum<k)
		sum+=arrey[i++];
	sum-=arrey[i];
	temp=m;
	k-=temp;
	while(temp>0){
		k-=temp;
		temp/=10;
	}
	temp=m;
	while(temp*10<arrey[i]){
		k-=temp;
		temp*=10;
	}
	k+=arrey[i];
	k=k+sum-(i+1)+2*m;
	if(k<0)k=0;
	printf("%ld\n",k);
	return ;
}

int main()
{
	int i;
	
	for(i=1,arrey[0]=1;i<10;i++)
		arrey[i]=arrey[i-1]*10;

	while(scanf("%ld%ld",&k,&m)!=EOF)
		solve();

	system("pause");
	return 0;
}

