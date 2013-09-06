#include <cstdio>
#include <cstring>

struct edge{
    int to,d;
    edge *next;
}edg[2000000],*vert[50010];

const int inf=1000000000;
int dis[50010],que[50010],flag[50010];

void Add_Edge(int x,int y,int va,int &top)
{
    //printf("%d->%d %d\n",x,y,va);
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];vert[x]=p;
}
int Spfa(int s,int t)
{
    int front=0,rear=1,n=t-s+2;
    for(int i=s;i<=t;i++){dis[i]=inf;  flag[i]=0;}
    dis[t]=0;   que[0]=t;  flag[t]=1;
    while(front!=rear)
    {
        int i=que[front];
        front=(front+1)%n;
        for(edge *p=vert[i];p;p=p->next)
        {
            if(dis[p->to]>dis[i]+p->d)
            {
                dis[p->to]=dis[i]+p->d;
                if(!flag[p->to]){
                    flag[p->to]=1;
                    que[rear]=p->to;
                    rear=(rear+1)%n;
                }
            }
        }
        flag[i]=0;
    }
    return dis[s];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int maxi=-inf,mini=inf,top=-1;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a<mini)mini=a;
            if(b+1>maxi)maxi=b+1;
            Add_Edge(b+1,a,-c,top);
        }
        for(int i=mini;i<maxi;i++)
        {
            Add_Edge(i,i+1,1,top);
            Add_Edge(i+1,i,0,top);
        }
        printf("%d\n",-Spfa(mini,maxi));
    }
    return 0;
}
