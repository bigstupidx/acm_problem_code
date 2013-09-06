#include<cstdio>
#include<cstring>
struct edge{
    int to;
    edge *next;
}edg[20010],*vert[4000],*r_vert[4000],r_edg[20010];
int n,top,oppo[4000],door[4000][2],v[4000],order[4000],id[4000];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&r_edg[top++];
    p->to=x;
    p->next=r_vert[y];r_vert[y]=p;
}
void DFS(int s)
{
    v[s]=1;
    for(edge *p=vert[s];p;p=p->next)
        if(!v[p->to])DFS(p->to);
    order[top++]=s;
}
void RG_DFS(int s)
{
    v[s]=1;
    id[s]=top;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!v[p->to])RG_DFS(p->to);
}
bool solve(int mid)
{
    top=0;
    memset(vert,0,sizeof(vert));
    memset(r_vert,0,sizeof(r_vert));
    for(int i=0;i<=mid;i++)
    {
        Add_Edge(door[i][0],oppo[door[i][1]]);
        Add_Edge(door[i][1],oppo[door[i][0]]);
    }
    memset(v,0,sizeof(v));top=0;
    memset(order,0,sizeof(order));
    for(int i=0;i<2*n;i++)
        if(!v[i])DFS(i);
    memset(v,0,sizeof(v));top=1;
    memset(id,0,sizeof(id));
    for(int i=2*n-1;i>=0;i--)
        if(!v[order[i]]){RG_DFS(order[i]);top++;}
    for(int i=0;i<2*n;i++)
        if(id[i]==id[oppo[i]])return false;
    return true;
}
int main( )
{
    int m;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            oppo[x]=y;oppo[y]=x;
        }
        for(int i=0;i<m;i++)
            scanf("%d%d",&door[i][0],&door[i][1]);
        int l=0,r=m-1,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(solve(mid)){l=mid+1;}
            else r=mid-1;
        }
        printf("%d\n",l);
    }
    return 0;
}