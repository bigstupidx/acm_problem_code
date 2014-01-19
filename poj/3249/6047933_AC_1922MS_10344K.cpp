#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[1000010],*vert[MAXN];
int in[MAXN], out[MAXN], va[MAXN], n, m;
__int64 ans[MAXN], inf = 1;
void add_edge(int x,int y,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int s)
{
    if(ans[s]!=-inf)
        return ;
    ans[s]=va[s];
    __int64 maxi=-inf;
    for(edge *p=vert[s];p;p=p->next){
        DFS(p->to);
        if(maxi<ans[p->to])
            maxi=ans[p->to];
    }
    if(maxi==-inf)maxi=0;
    ans[s] += maxi;
    return ;
}
__int64 solve()
{
    for(int i=1;i<=n;i++)ans[i]=-inf;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0){
            DFS(i);
        }
    }
    __int64 maxi=-inf;
    for(int i=1;i<=n;i++)
        if(in[i]==0&&maxi<ans[i])
            maxi=ans[i];
//    for(int i=1;i<=n;i++)
//        printf("%d ",ans[i]);
//    puts("");
    return maxi;
}
int main()
{
    inf<<=60;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int top=-1;
        for(int i=1;i<=n;i++)
            scanf("%d",va+i);
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add_edge(x,y,top);
            in[y]++;    out[x]++;
        }
        printf("%I64d\n",solve());
    }
    return 0;
}
