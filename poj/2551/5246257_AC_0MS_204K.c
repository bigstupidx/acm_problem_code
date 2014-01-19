#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		__int64 temp=1;
		int ans=1;
		while(temp%n){
			temp=(temp%n)*10+1;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}