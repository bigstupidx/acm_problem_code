#include<stdio.h>
#define MAX 10000

void bfs(int p)
{
	int queue[MAX];
	int rank[MAX];
	int front,rear,i,flag,flag1;
	if(p==1){
		printf("1\n");
		return ;
	}
	front=rear=0;
	queue[0]=1;
	queue[++rear]=2;
	rank[rear]=1;
	while(front!=rear){
		if(queue[++front]!=p){
			for(i=0,flag=1,flag1=1;i<=rear;i++){
				if(queue[front]+1==queue[i])
					flag=0;
				if(queue[front]-1==queue[i])
					flag1=0;
			}
			if(flag){
				queue[++rear]=queue[front]+1;
				rank[rear]=rank[front]+1;
			}
			if(flag1){
				queue[++rear]=queue[front]-1;
				rank[rear]=rank[front]+1;
			}
			queue[++rear]=(queue[front]*2);
			rank[rear]=rank[front]+1;
		}
		else{
			printf("%d\n",rank[front]);
			break;
		}
	}
	return ;
}
int main()
{
	int p;
	while(scanf("%d",&p)!=EOF)
		bfs(p);
	return 0;
}