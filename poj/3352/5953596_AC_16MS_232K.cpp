#include <cstdio>
#include <cstring>
struct edge{
    int to;
    edge *next;
}edg[100000],*vert[1002];
int n,m,anc[1002],par[1002],color[1002],brig[1002][2],dep[1002];
int id[1002],deg[1002];
void Add_Edge(int x,int y,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
int Find(int x)
{
    if(par[x]==-1)return x;
    return par[x]=Find(par[x]);
}
void DFS(int k,int k_father,int depth)
{
    color[k]=1;
    anc[k]=dep[k]=depth;
    for(edge *p=vert[k];p;p=p->next)
    {
        int i=p->to;
        if(i!=k_father && color[i]==1)
            anc[k]=anc[k]>dep[i]?dep[i]:anc[k];
        if(color[i]==0)
        {
            DFS(i,k,depth+1);
            anc[k]=anc[k]>anc[i]?anc[i]:anc[k];
            if(anc[i]<=dep[k])
            {
                int ii=Find(i),kk=Find(k);
                par[ii]=kk;
            }
            else{
                brig[m][0]=k;   brig[m++][1]=i;
            }
        }
    }
    color[k]=2;
}
int Solve()
{
    int cnt=0,ret=0;
    memset(id,0,sizeof(id));
    memset(deg,0,sizeof(deg));
    for(int i=1;i<=n;i++)
    {
        int j=Find(i);
        if(!id[j])id[j]=ret++;
    }
    for(int i=0;i<m;i++)
    {
        int j=Find(brig[i][0]);
        int k=Find(brig[i][1]);
        //printf("%d-%d\n",brig[i][0],brig[i][1]);
        deg[id[j]]++;   deg[id[k]]++;
    }
    for(int i=0;i<ret;i++)
        if(deg[i]==1)cnt++;
    return (cnt+1)/2;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int top=-1;
        memset(vert,0,sizeof(vert));
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            Add_Edge(x,y,top);Add_Edge(y,x,top);
        }
        m=0;
        memset(par,-1,sizeof(par));
        memset(color,0,sizeof(color));
        DFS(1,0,1);
        printf("%d\n",Solve());
    }
    return 0;
}
