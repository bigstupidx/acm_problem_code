#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
#include <queue>
#define N 2000
#define M 1000000
#define inf 1000000000
using namespace std;
struct edge{
    int u,v,c,f,next;
}e[M*2];

char str[2000];
int head[N],dist[N],now[N],pre[N],cnt[N],cur[N],tot;
int n,m,NUM;//n表示点数,m表示边数 ,NUM表示总点数

void add_edge(int u,int v,int va)
{
    //printf("%d -> %d %d\n",u,v,va);
    e[++tot].u = u; e[tot].v = v; e[tot].c = va;
    e[tot].f=0; e[tot].next = head[u]; head[u] = tot;

    e[++tot].u = v; e[tot].v = u; e[tot].c = 0;
    e[tot].f=0; e[tot].next = head[v]; head[v] = tot;
}

int max_flow(int st,int ed,int n)
{
    int tot_flow;//总流量 
    int i = st,j,t;
    int now_flow, found, mini;
    memset( dist, 0, sizeof( dist ) );
    memset( now, -1, sizeof( now ) );
    memset( cnt, 0, sizeof( cnt ) );
    tot_flow = 0; now_flow = inf;
    cnt[0] = NUM;
    while( dist[st] < NUM )
    {
        cur[i] = now_flow;      found = 0;
        if( now[i] == -1 ) t = head[i];
        else t = now[i];
        while( t != -1 )
        {
            j = e[t].v;
            if(e[t].c > e[t].f && dist[j] + 1 == dist[i])
            {
                found = 1; now[i] = t;
                if( e[t].c-e[t].f < now_flow )
                    now_flow = e[t].c-e[t].f;
                pre[j] = t; i = j;
                if(i == ed)
                {
                    tot_flow += now_flow;
                    while(i != st)
                    {
                        e[pre[i]].f += now_flow;
                        e[pre[i]^1].f -= now_flow;
                        i = e[pre[i]].u;
                    }
                    now_flow = inf;
                }
                break;
            }
            t = e[t].next;
        }
        if( found ) continue;
        if( --cnt[ dist[i] ] == 0) break;
        mini = n - 1;
        t = head[i];
        while( t != -1 )
        {
            if( e[t].c > e[t].f && dist[e[t].v] < mini )
            {
                mini = dist[e[t].v];
                now[i] = t;
            }
            t = e[t].next;
        }
        dist[i] = mini + 1;
        cnt[ dist[i] ]++;
        if( i != st )
        {
            i = e[ pre[i] ].u;
            now_flow = cur[i];
        }
    }
    return tot_flow;
}
void build_g(int mid,int t)
{
    for(int i=0;i<tot;i++)e[i].f=0;
    for(int i=n+1;i<=n+m;i++)
    {
        for(int j=head[i];j!=-1;j=e[j].next){
            if(e[j].v==t){
                e[j].c=mid;break;
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        tot=-1;getchar();
        memset(head,-1,sizeof(head));
        for(int i=1;i<=n;i++)
        {
            gets(str);
            string st(str);
            istringstream in(st);
            in>>str;
            //puts(str);
            int u;
            while(in>>u)add_edge(i,u+n+1,1);
            add_edge(0,i,1);
        }
        for(int i=n+1;i<=n+m;i++)
            add_edge(i,n+m+1,1);
        NUM=n+m+2;
        int l=0,r=n,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            build_g(mid,n+m+1);
            if(max_flow(0,n+m+1,n+m+1)==n)
                r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
