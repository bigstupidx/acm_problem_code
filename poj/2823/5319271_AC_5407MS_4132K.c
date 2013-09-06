#include<stdio.h>
#define MAX 1000010
int a[MAX],deque[MAX];
int n,k;
void dq1()
{
	int head,tail,i;
	head=tail=1;
	for(i=1;i<k;i++){
		while(head<=tail&&a[i]<a[deque[tail]])tail--;
		deque[++tail]=i;
	}
	for(;i<=n;i++)
	{
		if(deque[head]<i-k+1)head++;
		while(head<=tail&&a[i]<a[deque[tail]])tail--;
		deque[++tail]=i;
		printf("%d ",a[deque[head]]);
	}
	printf("\n");
	return ;
}
void dq2()
{
	int head,tail,i;
	head=tail=1;
	for(i=1;i<k;i++){
		while(head<=tail&&a[i]>a[deque[tail]])tail--;
		deque[++tail]=i;
	}
	for(;i<=n;i++)
	{
		if(deque[head]<i-k+1)head++;
		while(head<=tail&&a[i]>a[deque[tail]])tail--;
		deque[++tail]=i;
		printf("%d ",a[deque[head]]);
	}
	printf("\n");
	return ;
}
int main()
{
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	dq1();
	dq2();
	return 0;
}