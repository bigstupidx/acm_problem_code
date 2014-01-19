#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int max[12],min[12],arrey[24];
__int64 sum;
int n1,n2,n;

int mycmp(const void *e1,const void *e2)
{
	return *(int *)e2-*(int *)e1;
}
int mycmp1(const void *e1,const void *e2)
{
	return *(int *)e1-*(int *)e2;
}
void solve()
{
	int i,temp;
	sum=0;
	for(i=0;i<n1+n2;i++){
		scanf("%d",arrey+i);
		sum+=arrey[i];
	}
	qsort(arrey,n1+n2,sizeof(int),mycmp);
	for(i=0;i<n1;i++)	max[i]=arrey[i];
	for(i=n1;i<n2+n1;i++)	min[i-n1]=arrey[i];
	qsort(min,n2,sizeof(int),mycmp1);
	for(i=0;i<n-n1-n2;i++)
	{
		scanf("%d",&max[n1]);
		sum+=max[n1];
		if(max[n1]>max[n1-1])
			qsort(max,n1+1,sizeof(int),mycmp);
		if(min[n2-1]>max[n1]){
			min[n2]=max[n1];
			qsort(min,n2+1,sizeof(int),mycmp1);
		}
	}
	for(i=0;i<n1;i++)sum-=max[i];
	for(i=0;i<n2;i++)sum-=min[i];
	printf("%.6lf\n",(sum*1.0)/(n-n1-n2));
	return ;
}

int main()
{
	while(scanf("%d%d%d",&n1,&n2,&n),n||n1||n2)
		solve();
	return 0;
}