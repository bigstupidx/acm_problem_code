#include <cstdio>
#include <cstring>
struct edge{
    int to;
    int d;
    edge *next;
}edg[100010],*vert[1010];
int n,dis[1010],flag[1010],que[1010],cnt[1010];
const int inf = 1000000000;
void Add_Edge(int x,int y,int va,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
int Spfa()
{
    int ff=0,rr=1;
    for(int i=1;i<=n;i++){dis[i]=inf;flag[i]=0;cnt[i]=0;}
    que[0]=1;   dis[1]=0;   flag[1]=1;  cnt[1]=1;
    while(ff!=rr)
    {
        int u=que[ff];
        ff=(ff+1)%n;
        flag[u]=0;
        for(edge *p=vert[u];p;p=p->next)
        {
            int v=p->to;
            if(dis[v]>dis[u]+p->d)
            {
                dis[v]=dis[u]+p->d;
                if(!flag[v])
                {
                    flag[v]=1;
                    cnt[v]++;
                    if(cnt[v]>n)return -1;
                    que[rr]=v;
                    rr=(rr+1)%n;
                }
            }
        }
    }
    if(dis[n]==inf)return -2;
    return dis[n];
}
int main()
{
    int m1,m2;
    while(scanf("%d%d%d",&n,&m1,&m2)!=EOF)
    {
        int x,y,va,top=-1;
        memset(vert,0,sizeof(vert));
        while(m1--)
        {
            scanf("%d%d%d",&x,&y,&va);
            Add_Edge(x,y,va,top);
        }
        while(m2--)
        {
            scanf("%d%d%d",&x,&y,&va);
            Add_Edge(y,x,-va,top);
        }
        for(int i=1;i<n;i++)
            Add_Edge(i+1,i,-1,top);
        printf("%d\n",Spfa());
    }
    return 0;
}
