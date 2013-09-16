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
		__int64 sum=0;
		for(i=0;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			a[i]=x-y,b[i]=y-z,c[i]=x-z;
		}
		sort(a,a+n);
		sort(b,b+n);
		sort(c,c+n);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				sum+=((a[j]-a[i])+(b[j]-b[i])+(c[j]-c[i]))/2;
		printf("%I64d\n",sum);
	}
	return 0;
}
