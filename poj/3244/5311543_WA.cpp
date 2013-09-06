#include<stdio.h>
#include<algorithm>
#define MAX 200001
using namespace std;

int a[MAX],b[MAX],c[MAX];
int cmp(int &l,int &h)
{
	return l>h;
}
int main()
{
	int n;
	while(scanf("%d",&n),n){
		int i;
		__int64 x,y,z;
		__int64 sum=0;
		for(i=0;i<n;i++){
			scanf("%I64d%I64d%I64d",&x,&y,&z);
			a[i]=x-y,b[i]=y-z,c[i]=x-z;
		}
		if(n==1){
			printf("0\n");
			continue;
		}
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		sort(c,c+n,cmp);
		x=a[0]-a[1],y=b[0]-b[1],z=c[0]-c[1];
		sum+=(x+y+z)/2;
		for(i=2;i<n;i++){
			    x+=i*(a[i-1]-a[i]);
				y+=i*(b[i-1]-b[i]);
				z+=i*(c[i-1]-c[i]);
				sum+=(x+y+z)/2;
		}
		printf("%I64d\n",sum);
	}
	return 0;
}
