#include<cstdio>
#include<cstring>
#define N 2500
#define M 10010
struct edge{
    int to;
    edge *next;
}edg[M],*vert[N],*r_vert[N],r_edg[M];

int oppo[N],n,top,door[N][2],order[N],id[N],v[N];

void Add_Edge(int x,int y)
{
    edge *p=&edg[top++];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&edg[top++];
    p->to=x;
    p->next=r_vert[y];r_vert[y]=p;
}

void RG_DFS(int s)
{
    v[s]=1;
    id[s]=top;
    for(edge *p=vert[s];p;p=p->next)
        if(!v[p->to])RG_DFS(p->to);
    
}
void DFS(int s)
{
    v[s]=1;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!v[p->to])DFS(p->to);
    order[top++]=s;
}
bool solve(int mid)
{
    top=0;
    memset(vert,0,sizeof(vert));
    memset(r_vert,0,sizeof(r_vert));
    for(int i=0;i<mid;i++)
    {
        Add_Edge(door[i][0],oppo[door[i][1]]);
        Add_Edge(door[i][1],oppo[door[i][0]]);
    }
/**    for(int i=0;i<2*n;i++){
        for(edge *p=vert[i];p;p=p->next)
            printf("%d ",p->to);
        puts("");
    }
 * */
    top=0;
    memset(v,0,sizeof(v));
    for(int i=0;i<2*n;i++)
        if(!v[i])DFS( i );
    top=1;
    memset(v,0,sizeof(v));
    for(int i=2*n-1;i>=0;i--)
        if(!v[order[i]]){RG_DFS(order[i]);top++;}
    for(int i=0;i<2*n;i++)
        if(id[i]==id[oppo[i]])return false;
    return true;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m),n||m)
    {
        int x,y;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            oppo[x]=y;oppo[y]=x;
        }
        for(int i=0;i<m;i++)
            scanf("%d%d",&door[i][0],&door[i][1]);
        int l=1,h=m,mid;
        while(l<h)
        {
            mid=(l+h)/2;
//            printf("Try low,mid high:%d %d %d\n",l,mid,h);
            if(solve(mid))l=mid+1;
            else h=mid-1;
        }
        printf("%d\n",l);
    }
    return 0;
}
