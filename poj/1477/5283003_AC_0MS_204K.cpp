#include<stdio.h>
#include<algorithm>
using namespace std;
int a[60];
int main()
{
	int n,t=1;
	while(scanf("%d",&n),n){
		int i,sum=0,ans=0;
		for(i=0;i<n;i++){
			scanf("%d",a+i);
			sum+=a[i];
		}
		sort(a,a+n);
		i=0;sum/=n;
		while(sum>a[i]){
			ans+=sum-a[i];
			i++;
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",t++,ans);
	}
	return 0;
}