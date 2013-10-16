# include <iostream>
using namespace std;
#define inf 99999999
#define MAXN 30003
#define MAXE 150005
#define _clr(aa,val) (memset(aa,val,sizeof(aa)))
struct Edge
{
    int to,len,next;
}E[MAXE];
int p[MAXN],ec;
int stack[MAXE*5],dis[MAXN];
bool vis[MAXN];
void init_edge()
{
    _clr(p,0xff);
    ec=1;
}
void add(int a,int b,int c)
{
    E[ec].to=b;
    E[ec].len=c;
    E[ec].next=p[a];
    p[a]=ec++;
}

bool spfa(int n,int s)
{
    int top=0,v,i;
    _clr(vis,0);
    for (i=1;i<=n;i++) dis[i]=inf;
    dis[s]=0;vis[s]=1;
    stack[++top]=s;
    while (top)
    {
        v=stack[top--];
        vis[v]=0;
        for (i=p[v];i!=-1;i=E[i].next)
            if (dis[v] + E[i].len < dis[E[i].to]) //松弛
            {
                dis[E[i].to] = dis[v] + E[i].len;
                if (!vis[E[i].to])
                {
                    vis[E[i].to]=1;
                    stack[++top]=E[i].to;
                }
            }
    }
    return true;
}
int main()
{
    int m,n,i,a,b,c;
    init_edge();
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    spfa(n,1);
    cout<<dis[n]<<endl;
    return 0;
}