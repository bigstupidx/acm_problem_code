#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[1000010],*vert[MAXN];
int in[MAXN],out[MAXN],va[MAXN],n,m,ans[MAXN];
const int inf = 1000000000;
void add_edge(int x,int y,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
int solve()
{
    queue<int>Q;
    for(int i=1;i<=n;i++)ans[i]=-inf;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0){
            Q.push(i);
            ans[i]=va[i];
        }
    }
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        for(edge *p=vert[u];p;p=p->next)
        {
            if(ans[p->to]<ans[u]+va[p->to])
            {
                ans[p->to]=ans[u]+va[p->to];
                Q.push(p->to);
            }
        }
    }
    int maxi=-inf;
    for(int i=1;i<=n;i++)
        if(out[i]==0&&maxi<ans[i])
            maxi=ans[i];
//    for(int i=1;i<=n;i++)
//        printf("%d ",ans[i]);
//    puts("");
    return maxi;
}
int main()
{
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
        printf("%d\n",solve());
    }
    return 0;
}
