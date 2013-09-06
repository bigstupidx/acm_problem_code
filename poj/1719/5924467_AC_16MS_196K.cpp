#include<cstdio>
#include<cstring>
struct edge{
    int to;
    edge *next;
}e[10000],*vert[1002];
int n,m,my[1002],yy[1002][2];
bool flag[1002];
void Add_Edge(int u,int v,int &top)
{
    edge *p=&e[++top];
    p->to=v;
    p->next=vert[u];    vert[u]=p;
}
bool Path(int s)
{
    for(edge *p=vert[s];p;p=p->next)
    {
        if(!flag[p->to])
        {
            flag[p->to]=1;
            if(my[p->to]==-1||Path(my[p->to]))
            {
                my[p->to]=s;
                return true;
            }
        }
    }
    return false;
}
bool Max_Match()
{
    int ans=0;
    memset(my,-1,sizeof(my));
    for(int i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(Path(i))ans++;
    }
    return ans==n;
}
int main()
{
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
        int top=-1;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
            scanf("%d%d",&yy[i][0],&yy[i][1]);
        if(n>m){
            puts("NO");
            continue;
        }
        memset(vert,0,sizeof(vert));
        for(int i=1;i<=m;i++){
            Add_Edge(yy[i][0],i,top);
            Add_Edge(yy[i][1],i,top);
        }
        if(Max_Match())
        {
            for(int i=1;i<=m;i++){
                if(my[i]==-1)printf("%d ",yy[i][0]);
                else printf("%d ",my[i]);
            }
            puts("");
        }
        else puts("NO");
    }
    return 0;
}
