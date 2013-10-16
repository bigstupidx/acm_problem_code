#include<stdio.h>
#define MAX 100010
__int64 pre[MAX],next[MAX],arrey[MAX];
int n;
void fpre()
{
	int i,j;
	pre[1]=0;
	for(i=2;i<=n;i++)
		for(j=i-1;;j=pre[j])
			if(j<1||arrey[j]<arrey[i]){
				pre[i]=j;break;
			}
}

void fnext()
{
	int i,j;
	next[n]=n+1;
	for(i=n-1;i>=1;i--)
		for(j=i+1;;j=next[j])
			if(j>n||arrey[i]>arrey[j]){
				next[i]=j;break;
			}
}
int main()
{
	while(scanf("%d",&n),n){
		__int64 ans=0;
		int i;
		for(i=1;i<=n;i++)
			scanf("%I64d",&arrey[i]);
		fpre();
		fnext();
		for(i=1;i<=n;i++){
			__int64 temp=0;
			temp=arrey[i]*(next[i]-pre[i]-1);
			if(temp>ans)
				ans=temp;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}

