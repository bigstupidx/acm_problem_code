#include<stdio.h>
#include<algorithm>
using namespace std;

long sum;
int n1,n2,n;

int mycmp1(int x,int y)
{
	return x>y;
}
void solve()
{
    int i;
    int max[12],min[12],arrey[24];
	sum=0;
	for(i=0;i<n1+n2;i++){
		scanf("%d",arrey+i);
		sum+=arrey[i];
	}
	sort(arrey,arrey+n1+n2,mycmp1);
	for(i=0;i<n1;i++)	max[i]=arrey[i];
	for(i=n1;i<n2+n1;i++)	min[i-n1]=arrey[i];
	sort(min,min+n2);
	for(i=0;i<n-n1-n2;i++)
	{
		scanf("%d",&max[n1]);
		sum+=max[n1];
		if(max[n1]>max[n1-1])
			sort(max,max+n1+1,mycmp1);
		if(max[n1]<min[n2-1]){
			min[n2]=max[n1];
			sort(min,min+n2+1);
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
