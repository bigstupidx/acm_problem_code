#include <cstdio>
#include <cstring>
struct edge{
    int to;
    edge *next;
}edg[10010],*vert[1010];
int order[1010],tot;
bool map[1010][1010],visit[1010];
void Add_Edge(int x,int y)
{
    edge *p=&edg[++tot];
    p->to=y;
    p->next=vert[x]; vert[x]=p;
}
void DFS(int s,int cnt)
{
    order[cnt]=s;
    for(edge *p=vert[s];p;p=p->next)
    {
        for(int i=0;i<=cnt;i++)
            map[order[i]][p->to]=true;
        DFS(p->to,cnt+1);
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int ans,x,y;
        tot=-1;ans=0;
        memset(map,0,sizeof(map));
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=true;
            Add_Edge(x,y);
        }
        for(int i=1;i<=n;i++) DFS(i,0);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(!map[i][j]&&!map[j][i])ans++;
        printf("%d\n",ans);
    }
    return 0;
}
