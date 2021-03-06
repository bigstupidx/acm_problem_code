#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int arrey[21];
__int64 sum;
int n1,n2,n;

int mycmp(const void *e1,const void *e2)
{
	return *(int *)e2-*(int *)e1;
}

void xchange(int x)
{
	int high,middle,low;
	high=n1+n2-1,low=0;
	while(low<high)
	{
		middle=(low+high)/2;
		if(arrey[middle]==x)
			return ;
		if(arrey[middle]>x)
			low=middle+1;
		else
			high=middle-1;
	}
	middle=low;
	if((middle==(n1-1)&&arrey[middle]>x)||(middle==n1&&arrey[middle]<x))
		return ;
	else{
		int k;
		if(middle<n1-1){
			for(k=n1-1;k>middle;k--)
				arrey[k]=arrey[k-1];
			arrey[k]=x;
		}
		else{
			for(k=n1;k<middle;k++)
				arrey[k]=arrey[k+1];
			arrey[k]=x;
		}
	}
	return ;
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
	qsort(arrey,n1+n2,sizeof(int),mycmp);
	for(i=0;i<n-n1-n2;i++)
	{
		scanf("%d",&temp);
		sum+=temp;
		xchange(temp);
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