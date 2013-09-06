/*
用归并排序的方法
*/
#include <stdio.h>

int n;
int arr[500000];
int b[500000];
__int64 result;

int mergesort(int low,int high);
int merge(int low,int mid,int high);

int main()
{
	int i;
	while(1){
		result=0;
		scanf("%d",&n);
		if(n==0)
			break;
		for(i=1;i<=n;i++)
			scanf("%d",&arr[i]);
  
		mergesort(1,n);
		printf("%I64d\n",result);
	}
	return 0;
}

int mergesort(int low,int high)
{
	int mid;
	mid=(low+high)/2;
	if(low<high)
	{
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
	}
	return 0;
}

int merge(int low,int mid,int high)
{
	int i,j,k;
	for(i=low,j=low,k=mid+1;j<=mid&&k<=high;i++)
	{
		if(arr[j]>arr[k])
		{
			b[i]=arr[k];
			k++;
			result += mid - j + 1;//精髓所在
		}
		else
		{   
			b[i]=arr[j];
			j++;
		}
	}
	if(j==mid+1)
	{
		for(;k<=high;k++,i++)
			b[i]=arr[k];   
	}
	else if(k==high+1)
	{
		for(;j<=mid;j++,i++)
			b[i]=arr[j];
	}
	for(i=low;i<=high;i++)
	{
		arr[i]=b[i];
		//printf("%d ",arr[i]);
	}
	//printf("\n%d\n",result);
	return 0;
}