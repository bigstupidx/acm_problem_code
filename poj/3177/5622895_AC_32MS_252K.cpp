#include<cstdio>
#include<cstring>

struct edge{
    int to;
    edge *next;
}edg[20010],*vert[5010];
int n,top,deg[5010],anc[5010],deep[5010],c[5010],bridg[10010][2],par[5010];
int id[5010];
int F(int s)
{
    int t=par[s];
    if(t==-1)return s;
    return par[s]=F(t);
}
void Add_Edge(int x,int y)
{
    edge *p=&edg[top++];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&edg[top++];
    p->to=x;
    p->next=vert[y];vert[y]=p;
}
void DFS(int k,int k_father,int depth)
{
    c[k]=1;
    anc[k]=deep[k]=depth;
    for(edge *p=vert[k];p;p=p->next)
    {
        int i=p->to;
        if(c[i]==1&&i!=k_father)
            anc[k]=anc[k]>deep[i]?deep[i]:anc[k];
        if(c[i]==0)
        {
            DFS(i,k,depth+1);
            anc[k]=anc[k]>anc[i]?anc[i]:anc[k];
            if(anc[i]<=deep[k])
            {
                int ii=F(i),jj=F(k);
                par[ii]=jj;
            }
            else
            {
                bridg[top][0]=k;
                bridg[top++][1]=i;
            }
        }
    }
    c[k]=2;
}
int Result_DFS()
{
    int count=0,ret=0;
    memset(id,0,sizeof(id));
    for(int i=1;i<=n;i++)
    {
        int j=F(i);
        if(!id[j])id[j]=++ret;
        id[i]=id[j];
    }
    /*for(int i=1;i<=n;i++)
        printf("%d ",id[i]);
    puts("");*/
    memset(deg,0,sizeof(deg));
    //printf("Bridge:\n");
    for(int i=0;i<top;i++)
    {
        int j,k;
        j=bridg[i][0];k=bridg[i][1];
      //  printf("%d %d\n",j,k);
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
        top=0;
        memset(vert,0,sizeof(vert));
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            Add_Edge(x,y);
        }
        top=0;
        memset(c,0,sizeof(c));
        memset(par,-1,sizeof(par));
        DFS(1,0,1);
        /*printf("Anc: ");
        for(int i=1;i<=n;i++)
            printf("%d ",anc[i]);
        printf("\n");
        printf("Deep: ");
        for(int i=1;i<=n;i++)
            printf("%d ",deep[i]);
        puts("");*/
        printf("%d\n",Result_DFS());
    }
    return 0;
}
