#include<stdio.h>
#define MAX 1000010
int min[2][MAX],max[2][MAX];
int n,k,now,t;

void intial_rmq()
{
	int j=1,i;
	t=1;
	if(k==1)return ;
	while(t*=2,j++,t<=k){
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
	while(scanf("%d%d",&n,&k)!=EOF){
		int i;
		for(i=1;i<=n;i++){
			scanf("%d",min[0]+i);
			max[0][i]=min[0][i];
		}
		intial_rmq();
		if(t==1||t==2*k)t=0;
		else t/=2;
		for(i=k;i<n;i++)
			printf("%d ",min[now][i]>min[now][i-t]?min[now][i-t]:min[now][i]);
		printf("%d\n",min[now][i]>min[now][i-t]?min[now][i-t]:min[now][i]);
		for(i=k;i<n;i++)
			printf("%d ",max[now][i]>max[now][i-t]?max[now][i]:max[now][i-t]);
		printf("%d\n",max[now][i]>max[now][i-t]?max[now][i]:max[now][i-t]);
	}
	return 0;
}