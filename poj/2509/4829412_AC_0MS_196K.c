#include<stdio.h>
int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)==2){
		int count=n,temp;
		while(n>=k){count+=n/k;n=n/k+n%k;}
		printf("%d\n",count);
	}
	return 0;
}

