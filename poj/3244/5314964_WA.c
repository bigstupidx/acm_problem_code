#include<stdio.h>
#include<stdlib.h>
#define MAX 200001

int a[MAX],b[MAX],c[MAX];
int comp(const void *e1,const void *e2)
{
	return *(int *)e2-*(int *)e1;
}
int main()
{
	int n;
	while(scanf("%d",&n),n){
		int i;
		long long  x,y,z;
		long long sum=0;
		for(i=0;i<n;i++){
			scanf("%lld%lld%lld",&x,&y,&z);
			a[i]=x-y,b[i]=y-z,c[i]=x-z;
		}
		qsort(a,n,sizeof(int),comp);
		qsort(b,n,sizeof(int),comp);
		qsort(c,n,sizeof(int),comp);
		x=a[0]-a[1],y=b[0]-b[1],z=c[0]-c[1];
		sum+=(x+y+z)/2;
		for(i=2;i<n;i++){
			    x+=i*(a[i-1]-a[i]);
				y+=i*(b[i-1]-b[i]);
				z+=i*(c[i-1]-c[i]);
				sum+=(x+y+z)/2;
		}
		printf("%lld\n",sum);
	}
	return 0;
}


