#include<cstdio>
#include<cstring>
struct edge{
    int to;
    edge *next;
}edg[1000000],*vert[1010];
int n,ans[1010],anc[1010],dep[1010],color[1010];
void Add_Edge(int x,int y,int &top)
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
        int i=p->to;
        if(i!=k_father && color[i]==1)
            anc[k]=anc[k]>dep[i]?dep[i]:anc[k];
        if(color[i]==0)
        {
            tot++;
            DFS(i,k,depth+1);
            anc[k]=anc[i]>anc[k]?anc[k]:anc[i];
            if(k_father==0&&tot>1||k_father!=0&&anc[i]>=dep[k])
                ans[k]++;
        }
    }
    color[k]=2;
}
int main()
{
    int x,y,nca=0;
    while(scanf("%d",&x),x)
    {
        n=x;    nca++;
        int top=-1;
        scanf("%d",&y);
        if(n<y)n=y;
        memset(vert,0,sizeof(vert));
        Add_Edge(x,y,top);
        Add_Edge(y,x,top);
        while(scanf("%d",&x),x)
        {
            if(n<x)n=x;
            scanf("%d",&y);
            if(n<y)n=y;
            Add_Edge(x,y,top);
            Add_Edge(y,x,top);
        }
        printf("Network #%d\n",nca);
        memset(color,0,sizeof(color));
        memset(dep,0,sizeof(dep));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)
            if(!color[i])DFS(i,0,1);
        int flag=0;
        for(int i=1;i<=n;i++)
            if(ans[i]>0){
                flag=1;
                printf("    SPF node %d leaves %d subnets\n",i,ans[i]+1);
            }
        if(!flag)puts("  No SPF nodes");
    }
    return 0;
}
