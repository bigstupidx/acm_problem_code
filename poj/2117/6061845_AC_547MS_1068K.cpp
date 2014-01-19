#include <cstdio>
#include <cstring>
struct edge{
    int to;
    edge *next;
}edg[8000000],*vert[10010];
int n,m,anc[10010],dep[10010],color[10010];
int part[10010],ans[10010],par[10010];
void add_edge(int x,int y,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int k,int k_father,int depth,int id)
{
    anc[k]=depth;   dep[k]=depth;
    color[k]=1; par[k]=id;  part[id]++;
    int tot=0;
    for(edge *p=vert[k];p;p=p->next)
    {
        int i=p->to;
        if(i!=k_father && color[i]==1)
            anc[k]=anc[k]>dep[i]?dep[i]:anc[k];
        if(color[i]==0)
        {
            tot++;
            DFS(i,k,depth+1,id);
            anc[k]=anc[i]>anc[k]?anc[k]:anc[i];
            if(k_father==0&&tot>1||k_father!=0&&anc[i]>=dep[k])
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
        memset(ans,0,sizeof(ans));
        memset(par,0,sizeof(par));
        memset(part,0,sizeof(part));
        memset(color,0,sizeof(color));
        for(int i=1;i<=n;i++)
            if(!color[i]){
                DFS(i,0,1,parts);
                parts++;
        }
        //for(int i=1;i<=n;i++)
        //    printf("%d ",ans[i]);
        //puts("");
        int maxi=-1;
        for(int i=1;i<=n;i++)
        {
            if(part[par[i]]>1&&maxi<ans[i]+parts)
                maxi=ans[i]+parts;
            if(part[par[i]]==1&&maxi<parts-1)
                maxi=parts-1;
        }
        printf("%d\n",maxi);
    }
    return 0;
}
