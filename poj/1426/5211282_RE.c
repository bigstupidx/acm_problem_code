#include<stdio.h>
#define MAX 1000000
__int64 queue[MAX];
int n;

void bfs()
{
	int rear,front;
	rear=1;
	front=0;
	queue[0]=1;
	while(front!=rear){
		__int64 temp;
		temp=queue[front++];
		if(temp%n==0){
			printf("%I64d\n",temp);
			return ;
		}
		queue[rear++]=temp*10;
		queue[rear++]=temp*10+1;
	}
	return ;
}
int main()
{
	while(scanf("%d",&n),n)
		bfs();
	return 0;
}