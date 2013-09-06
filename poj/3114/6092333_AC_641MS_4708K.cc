#include <cstdio>
#include <cstring>
#define MAXN 600
struct edge {
    int to;
    int d;
    edge *next;
}edg[1000000],*vert[MAXN],*r_vert[MAXN];
int order[MAXN],visit[MAXN],id[MAXN],n,m,top,dis[MAXN][MAXN];
const int inf = 1000000000;
void add_edge(int x,int y,int va)
{
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
    
    p=&edg[++top];
    p->to=x;
    p->d=va;
    p->next=r_vert[y];  r_vert[y]=p;
}
void DFS(int s)
{
    visit[s]=1;
    for(edge *p=vert[s];p;p=p->next)
        if(!visit[p->to])DFS(p->to);
    order[top++]=s;
}
void DFS_RG(int s)
{
    visit[s]=1;
    id[s]=top;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!visit[p->to])DFS_RG(p->to);
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        top=-1;
        memset(vert,0,sizeof(vert));
        memset(r_vert,0,sizeof(r_vert));
        for(int i=0;i<m;i++)
        {
            int x,y,va;
            scanf("%d%d%d",&x,&y,&va);
            add_edge(x,y,va);
        }
        top=1;
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=n;i++)
            if(!visit[i])DFS(i);
        
        top=1;
        memset(visit,0,sizeof(visit));
        for(int i=n;i>0;i--)
            if(!visit[order[i]]){DFS_RG(order[i]);top++;}
        
        for(int i=1;i<top;i++)
        {
            for(int j=1;j<top;j++)
                dis[i][j]=inf;
            dis[i][i]=0;
        }
        
        for(int i=1;i<=n;i++)
            for(edge *p=vert[i];p;p=p->next)
                if(id[i]!=id[p->to]&&dis[id[i]][id[p->to]]>p->d)
                    dis[id[i]][id[p->to]]=p->d;
        for(int w=1;w<top;w++)
            for(int u=1;u<top;u++)
                if(dis[u][w]<inf)
                    for(int v=1;v<top;v++)
                        if(dis[u][v]>dis[u][w]+dis[w][v])
                            dis[u][v]=dis[u][w]+dis[w][v];
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int u,v,tem;
            scanf("%d%d",&u,&v);
            tem=dis[id[u]][id[v]];
            if(tem==inf)
                puts("Nao e possivel entregar a carta");
            else
                printf("%d\n",tem);
        }
        puts("");
    }
    return 0;
}
