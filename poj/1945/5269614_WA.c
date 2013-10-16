#include<stdio.h>
#include<string.h>
#define MAX 50000

int queue[MAX],rank[MAX];
int aa[MAX];
void bfs(int p)
{
	int front,rear;
	if(p==1){
		printf("0\n");
		return ;
	}
	front=rear=0;
	aa[1]=aa[2]=1;
	queue[++rear]=2;
	rank[rear]=1;
	while(front!=rear){
		if(queue[++front]!=p&&queue[front]<=5000){
			if(!aa[queue[front]+1]){
				queue[++rear]=queue[front]+1;
				rank[rear]=rank[front]+1;
				aa[queue[front]+1]=1;
			}
			if(!aa[queue[front]-1]){
				queue[++rear]=queue[front]-1;
				rank[rear]=rank[front]+1;
				aa[queue[front]-1]=1;
			}
			if(queue[front]*2<5000&&!aa[queue[front]*2]){
				queue[++rear]=queue[front]*2;
				rank[rear]=rank[front]+1;
				aa[queue[front]*2]=1;
			}
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
	memset(aa,0,sizeof(aa));
	while(scanf("%d",&p)!=EOF)
		bfs(p);
	return 0;
}