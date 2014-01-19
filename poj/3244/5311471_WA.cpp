#include<stdio.h>
#define MAX 200001
#include<algorithm>
using namespace std;

int a[MAX],b[MAX],c[MAX];
int main()
{
	int n;
	while(scanf("%d",&n),n){
		int i,j;
		int x,y,z;
		__int64 sum=0,temp;
		for(i=0;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			a[i]=x-y,b[i]=y-z,c[i]=x-z;
		}
		sort(a,a+n);
		sort(b,b+n);
		sort(c,c+n);
		x=a[0],y=b[0],z=c[0];
		for(i=1;i<n;i++){
				temp=a[i]*i-x+b[i]*i-y+c[i]*i-z;
				sum+=temp/2;
				x+=a[i];
				y+=b[i];
				z+=c[i];
		}
		printf("%I64d\n",sum);
	}
	return 0;
}
