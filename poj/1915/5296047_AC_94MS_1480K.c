#include<stdio.h>
#include<string.h>
#define MAX 305

typedef struct node{
       int x,y;
}node;
node start,end,next;
node queue[100001];

int dir[8][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};
int used[MAX][MAX],steps[MAX][MAX];
int n;

int place()
{
    if(next.x<n&&next.x>=0&&next.y<n&&next.y>=0)
                                                return 1;
    return 0;
}
int bfs()
{
    
    int front,rear;
    int xx,yy,x,y,i;
    node temp;
    front=rear=0;
    if(start.x==end.x&&start.y==end.y)
    return 0;
    used[start.x][start.y]=1;
    steps[start.x][start.y]=1;
    used[end.x][end.y]=2;
    steps[end.x][end.y]=0;
    queue[++rear]=start;
    queue[++rear]=end;
    while(front<=rear){
                       temp=queue[++front];
                       x=temp.x;y=temp.y;
                       for(i=0;i<8;i++)
                       {
                                       xx=x+dir[i][0];
                                       yy=y+dir[i][1];
                                       next.x=xx;next.y=yy;
                                       if(place()){
                                                   if(used[xx][yy]==0)
                                                   {
                                                   used[xx][yy]=used[x][y];
                                                   steps[xx][yy]=steps[x][y]+1;
                                                   queue[++rear]=next;
                                                   }
                                                   else if(used[x][y]!=used[xx][yy])
                                                   return steps[xx][yy]+steps[x][y];
                                       }
                       }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               scanf("%d",&n);
               scanf("%d%d%d%d",&start.x,&start.y,&end.x,&end.y);
               memset(used,0,sizeof(used));
               memset(steps,0,sizeof(steps));
               printf("%d\n",bfs());               
    }
    return 0;
}
