#include<cstdio>
#include<cstring>
struct edge{
    int to;
    edge *next;
}edg[2010],*vert[1010];
int n,top,color[1010],anc[1010],deep[1010],par[1010];
int bridg[1010][2],deg[1010],id[1010];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top++];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&edg[top++];
    p->to=x;
    p->next=vert[y];vert[y]=p;
}
int F(int s)
{
    int t=par[s];
    if(t==-1)return s;
    return par[s]=F( t );
}
void DFS(int k,int k_father,int depth)
{
    color[k]=1;
    anc[k]=deep[k]=depth;
    for(edge *p=vert[k];p;p=p->next)
    {
        int i=p->to;
        if(color[i]==1&&i!=k_father)
            anc[k]=anc[k]>deep[i]?deep[i]:anc[k];
        if(color[i]==0)
        {
            DFS(i,k,depth+1);
            anc[k]=anc[k]>anc[i]?anc[i]:anc[k];
            if(anc[i]<=deep[k])
            {
                int ii=F(i),kk=F(k);
                par[ii]=kk;
            }
            else
            {
                bridg[top][0]=k;
                bridg[top++][1]=i;
            }
        }
    }
    color[k]=2;
}
int Result_DFS()
{
    int count=0,ret=0;
    memset(id,0,sizeof(id));
    for(int i=1;i<=n;i++)
    {
        int j=F( i );
        if(!id[j])id[j]=++ret;
        id[i]=id[j];
    }
    memset(deg,0,sizeof(deg));
    for(int i=0;i<top;i++)
    {
        int j=bridg[i][0],k=bridg[i][1];
        deg[id[j]]++;deg[id[k]]++;
    }
    for(int i=1;i<=ret;i++)
        if(deg[i]==1)count++;
    return (count+1)/2;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(vert,0,sizeof(vert));
        top=0;
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            Add_Edge(x,y);
        }
        top=0;
        memset(par,-1,sizeof(par));
        DFS(1,0,1);
        printf("%d\n",Result_DFS());
    }
    return 0;
}