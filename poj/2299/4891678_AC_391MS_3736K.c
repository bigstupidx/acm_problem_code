
#include<stdio.h>

int n;
__int64 ans;
int arr[500001],b[500001];

void merge(int low,int middle,int high)
{
	int i,j,k;
	for(i=low,j=low,k=middle+1;j<=middle&&k<=high;i++)
	{
		if(arr[j]>arr[k]){
			b[i]=arr[k];
			k++;
			ans+=middle-j+1;
		}
		else{
			b[i]=arr[j];
			j++;
		}
	}
	if(j==middle+1){
		for(;k<=high;k++)
			b[i++]=arr[k];
	}
	if(k==high+1){
		for(;j<=middle;j++)
			b[i++]=arr[j];
	}
	for(i=low;i<=high;i++)
		arr[i]=b[i];
	return;
}

void mergesort(int low,int high)
{
	int middle;
	middle=(low+high)/2;
	if(low<high){
		mergesort(low,middle);
		mergesort(middle+1,high);
		merge(low,middle,high);
	}
	return;
}

int main()
{
	while(scanf("%d",&n),n){
		int i;
		ans=0;
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		mergesort(0,n-1);
		printf("%I64d\n",ans);
	}
	return 0;
}
