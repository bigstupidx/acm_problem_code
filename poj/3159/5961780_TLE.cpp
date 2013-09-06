#include <cstdio>
#include <cstring>
struct edge{
    int to;
    int d;
    edge *next;
}edg[150010],*vert[30010];
int n,dis[30010],flag[30010],que[30010];
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
    for(int i=1;i<=n;i++){flag[i]=0;dis[i]=inf;}
    flag[1]=1; dis[1]=0; que[0]=1;
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
                    que[rr]=v;
                    rr=(rr+1)%n;
                }
            }
        }
    }
    return dis[n];
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int top=-1;
        memset(vert,0,sizeof(vert));
        while(m--){
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            Add_Edge(x,y,c,top);
        }
        printf("%d\n",Spfa());
    }
    return 0;
}
