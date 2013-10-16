#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int arrey[22];
__int64 sum;
int n1,n2,n;

int mycmp(const void *e1,const void *e2)
{
	return *(int *)e2-*(int *)e1;
}

void solve()
{
	int i,temp;
	double ans;
	sum=0;
	memset(arrey,0,sizeof(arrey));
	for(i=0;i<n1+n2;i++){
		scanf("%d",arrey+i);
		sum+=arrey[i];
	}
	for(i=0;i<n-n1-n2;i++)
	{
		int k;
		scanf("%d",&temp);
		sum+=temp;
		arrey[n1+n2]=temp;
		qsort(arrey,n1+n2+1,sizeof(int),mycmp);
		for(k=n1;k<n2+n1;k++)
			arrey[k]=arrey[k+1];
	}
	for(i=0;i<n1+n2;i++)
		sum-=arrey[i];
	ans=(sum*1.0)/(n-n1-n2);
	printf("%.6lf\n",ans);
	return ;
}

int main()
{
	while(scanf("%d%d%d",&n1,&n2,&n),n||n1||n2)
		solve();
	return 0;
}