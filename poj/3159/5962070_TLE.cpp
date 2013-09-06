#include <cstdio>
#include <cstring>
struct edge{
    int to;
    int d;
    int next;
}e[150010];
int n,top,dis[30010],flag[30010],S[30010],head[30010];
const int inf = 1000000000;
void Add_Edge(int x,int y,int va)
{
    e[++top].to=y;  e[top].d=va;
    e[top].next=head[x];    head[x]=top;
}
int Spfa()
{
    int ff=0,rr=1;
    for(int i=1;i<=n;i++){dis[i]=inf;flag[i]=0;}
    dis[1]=0;   S[0]=1;  flag[1]=1;
    while(ff!=rr)
    {
        int u=S[ff];
        ff=(ff+1)%n;
        flag[u]=0;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            if(dis[e[i].to]>dis[u]+e[i].d)
            {
                dis[e[i].to]=dis[u]+e[i].d;
                if(!flag[e[i].to]){
                    flag[e[i].to]=1;
                    S[rr]=e[i].to;
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
        top=-1;
        memset(head,-1,sizeof(head));
        while(m--){
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            Add_Edge(x,y,c);
        }
        printf("%d\n",Spfa());
    }
    return 0;
}
