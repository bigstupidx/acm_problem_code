#include<stdio.h>
long n,q;
long num[100010],sum[100010];
long count;
long a1,b1;
void solve()
{
	long i,j,k,temp;
	long s=0,e;
	for(i=0;i<n;i++){
		s+=sum[i];
		if(s>=a1)break;
	}
	for(j=i,e=s-sum[i];j<n;j++){
		e+=sum[j];
		if(e>=b1)break;
	}
	temp=s-a1;
	for(k=i+1;k<j;k++)
		if(temp<sum[k])temp=sum[k];
	if(temp<sum[j]-(e-b1))temp=sum[j]-(e-b1);
	printf("%ld\n",temp);
}

int main()
{
	while(scanf("%ld",&n),n){
		long i,j=0,a;
		count=1;
		scanf("%ld",&q);
		scanf("%ld",&num[0]);
		for(i=1;i<n;i++){
			scanf("%ld",&num[i]);
			if(num[i]==num[i-1]){count++;continue;}
			sum[j++]=count;
			count=1;
		}
		sum[j]=count;
		for(i=0;i<q;i++){
			scanf("%ld%ld",&a1,&b1);
			solve();
		}
	}
	return 0;
}