#include <cstdio>
#include <cstring>
using namespace std;
const int Len=100005;
#define max(a,b) (a>b?a:b)
struct edge{
    int to;
    edge *next;
}edg[1000010],*vert[Len];
int in[Len], va[Len], n, m;
void add_edge(int x,int y,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
long long dp[Len];
void DFS(int s)
{
    if(dp[s]!=-2000000001)
        return ;
    dp[s]=va[s];
    long long maxi=-2000000001;
    for(edge *p=vert[s];p;p=p->next){
        DFS(p->to);
        if(maxi<dp[p->to])
            maxi=dp[p->to];
    }
    if(maxi==-2000000001)maxi=0;
    dp[s] += maxi;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int top=-1;
        memset(in,0,sizeof(in));
        memset(vert,0,sizeof(vert));
        for(int i=1;i<=n;i++)scanf("%d",va+i);
        for(int j=1;j<=m;++j)
        {
             int s,e;
             scanf("%d%d",&s,&e);
             add_edge(s,e,top);
             in[e]++;
        }
        for(int i=1;i<=n;++i)
            dp[i]=-2000000001;
        for(int i=1;i<=n;i++){
            if(in[i]==0)DFS(i);
        }
        long long ans=-2000000001;
        for(int i=1;i<=n;++i)
           if(in[i]==0) ans=max(dp[i],ans);
        printf("%lld\n",ans);
    }
    return 0;
}
