#include <cstdio>
#include <cstring>
struct edge{
    int to;
    edge *next;
}edg[10000000],*vert[1010];
int n,m,anc[1010],dep[1010],color[1010],ans[1010];
void add_edge(int x,int y,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int k,int k_father,int depth)
{
    color[k]=1;
    anc[k]=dep[k]=depth;
    int tot=0;
    for(edge *p=vert[k];p;p=p->next)
    {
        int u=p->to;
        if(color[u]==1&&u!=k_father)
            anc[k]=anc[k]>dep[u]?dep[u]:anc[k];
        if(color[u]==0)
        {
            tot++;
            DFS(u,k,depth+1);
            anc[k]=anc[u]>anc[k]?anc[k]:anc[u];
            if(k_father==0&&tot>1||k_father!=0&&anc[u]>=dep[k])
                ans[k]++;
        }
    }
    color[k]=2;
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        int top=-1,parts=0;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++;    y++;
            add_edge(x,y,top);add_edge(y,x,top);
        }
        memset(color,0,sizeof(color));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)
            if(!color[i]){DFS(i,0,1);parts++;}
        int maxi=-1;
        for(int i=1;i<=n;i++)
            if(maxi<ans[i]+1)
                maxi=ans[i]+1;
        printf("%d\n",maxi+parts-1);
    }
    return 0;
}
