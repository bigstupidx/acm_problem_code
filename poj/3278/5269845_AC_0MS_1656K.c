#include<stdio.h>
#include<string.h>
#define MAX 200001

struct Queue{
	int x,step;
}queue[MAX];
int visit[MAX];
int n,k;

int bfs()
{
	struct Queue l;
	int front=0,rear=0,i;

	queue[++rear].x=n;
	queue[rear].step=0;
	visit[n]=1;
	while(front<=rear){
		l.x=queue[++front].x;
		l.step=queue[front].step;
		if(l.x==k)
			return l.step;
		for(i=0;i<3;i++){
			if(i==0){
				if(l.x>0&&!visit[l.x-1])
					queue[++rear].x=l.x-1,queue[rear].step=l.step+1,visit[l.x-1]=1;
			}
			else if(i==1){
				if(l.x<100001&&!visit[l.x+1])
					queue[++rear].x=l.x+1,queue[rear].step=l.step+1,visit[l.x+1]=1;
			}
			else{
				if(l.x*2<100001&&!visit[l.x*2])
					queue[++rear].x=l.x*2,queue[rear].step=l.step+1,visit[l.x*2]=1;
			}
		}
	}
}
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF){
		if(n>=k){
			printf("%d\n",n-k);
			continue;
		}
		memset(visit,0,sizeof(visit));
		printf("%d\n",bfs());
	}
	return 0;
}