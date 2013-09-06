#include<stdio.h>
#define MAX 1000010
int min[2][MAX],max[2][MAX];
int n,k,now;

void intial_rmq()
{
	int i,t=1;
	now=0;
	if(k==1)return ;
	while(t*=2,t<=k){
		now=1-now;
		for(i=t;i<=n;i++){
			min[now][i]=min[1-now][i]<min[1-now][i-t/2]?min[1-now][i]:min[1-now][i-t/2];
			max[now][i]=max[1-now][i]>max[1-now][i-t/2]?max[1-now][i]:max[1-now][i-t/2];
		}
	}
	return ;
}
 
int main()
{
	int i,t;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",min[0]+i);
		max[0][i]=min[0][i];
	}
	intial_rmq();
	t=1;
	while(t*2<=k)t*=2;
	for(i=k;i<n;i++)
		printf("%d ",min[now][i]>min[now][i+t-k]?min[now][i-k+t]:min[now][i]);
	printf("%d\n",min[now][i]>min[now][i-k+t]?min[now][i-k+t]:min[now][i]);
	for(i=k;i<n;i++)
		printf("%d ",max[now][i]>max[now][i-k+t]?max[now][i]:max[now][i-k+t]);
	printf("%d\n",max[now][i]>max[now][i-k+t]?max[now][i]:max[now][i-k+t]);
	return 0;
}
