#include<stdio.h>
int n,ans[13],data[13],j,flag;
void mysearch(int k,int total)
{
	int i;
	if(total==0)
	{
		for(flag=i=1,printf("%d",ans[0]);i<j;i++)
			printf("+%d",ans[i]);
		printf("\n");
		return ;
	}
	if(k>=n||total<0)return ;
	for(i=k;i<n;i++)
		if(i==k||data[i]!=data[i-1])
		{
			ans[j++]=data[i];
			mysearch(i+1,total-data[i]);
			j--;
		}
	return ;
}
int main()
{
	int t;
	while(scanf("%d%d",&t,&n),n){
		int i;
		j=flag=0;
		for(i=0;i<n;i++)
			scanf("%d",data+i);
		printf("Sums of %d:\n",t);
		mysearch(0,t);
		if(!flag)printf("NONE\n");
	}
	return 0;
}