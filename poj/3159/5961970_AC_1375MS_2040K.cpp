#include <cstdio>
#include <cstring>
struct edge{
    int to;
    int d;
    int next;
}e[150010];
int n,dis[30010],flag[30010],S[30010],head[30010];
const int inf = 1000000000;
void Add_Edge(int x,int y,int va,int &top)
{
    e[++top].to=y;
    e[top].d=va;
    e[top].next=head[x];    head[x]=top;
}
int Spfa()
{
    int top=0;
    for(int i=1;i<=n;i++){dis[i]=inf;flag[i]=0;}
    dis[1]=0;   S[++top]=1;  flag[1]=1;
    while(top)
    {
        int u=S[top--];
        flag[u]=0;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            if(dis[e[i].to]>dis[u]+e[i].d)
            {
                dis[e[i].to]=dis[u]+e[i].d;
                if(!flag[e[i].to])S[++top]=e[i].to;
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
        memset(head,-1,sizeof(head));
        while(m--){
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            Add_Edge(x,y,c,top);
        }
        printf("%d\n",Spfa());
    }
    return 0;
}
