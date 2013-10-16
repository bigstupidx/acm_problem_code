#include<cstdio>
#include<cstring>
#define N 5010
#define M 1000000
#define inf 1000000000
struct edge{
    int u,v,c;
    int next;
}e[M*2];
int head[N],dist[N],now[N],pre[N],cnt[N],cur[N];
int n,m,tot;//tot,n表示点数,m表示边数 
void Add_Edge(int u,int v,int va)
{
    e[++tot].u = u; e[tot].v = v; e[tot].c = va;
    e[tot].next = head[u]; head[u] = tot;

    e[++tot].u = v; e[tot].v = u; e[tot].c = 0;
    e[tot].next = head[v]; head[v] = tot;
}
int Sap_Flow(int st,int ed)
{
    int tot_flow;
    int i = st,j,t;
    int now_flow, found, mini;
    memset(dist, 0, sizeof(dist));
    memset(now, -1, sizeof(now));
    memset( cnt, 0, sizeof(cnt));
    tot_flow = 0; now_flow = inf;
    cnt[0] = n;
    while(dist[st] < n)
    {
        cur[i] = now_flow; found = 0;
        if(now[i] == -1) t = head[i];
        else t = now[i];
        while(t != -1)
        {
            j = e[t].v;
            if(e[t].c > 0 && dist[j] + 1 == dist[i])
            {
                found = 1; now[i] = t;
                if(e[t].c < now_flow) now_flow = e[t].c;
                pre[j] = t; i = j;
                if(i == ed)
                {
                    tot_flow += now_flow;
                    while(i != st)
                    {
                        e[pre[i]].c -= now_flow;
                        e[pre[i]^1].c += now_flow;
                        i = e[pre[i]].u;
                    }
                    now_flow = inf;
                }
                break;
            }
            t = e[t].next;
        }
        if(found) continue;
        if(--cnt[dist[i]] == 0) break;
        mini = n - 1;
        t = head[i];
        while(t != -1)
        {
            if(e[t].c > 0 && dist[e[t].v] < mini)
            {
                mini = dist[e[t].v];
                now[i] = t;
            }
            t = e[t].next;
        }
        dist[i] = mini + 1;
        cnt[dist[i]]++;
        if(i != st)
        {
            i = e[pre[i]].u;
            now_flow = cur[i];
        }
    }
    return tot_flow;
}
int main()
{
    int c,l;
    while(scanf("%d%d",&c,&l)!=EOF)
    {
        tot=-1;
        memset(head,-1,sizeof(head));
        for(int i=1;i<=c;i++){
            scanf("%d%d",&cur[i],&cnt[i]);
            Add_Edge(0,i,1);
        }
        for(int i=1;i<=l;i++)
        {
            int rate,va;
            scanf("%d%d",&rate,&va);
            for(int j=1;j<=c;j++)
            {
                if(cur[j]<=rate&&cnt[j]>=rate)
                    Add_Edge(j,i+c,inf);
            }
            Add_Edge(c+i,l+c+1,va);
        }
        n=l+c+2;
        printf("%d\n",Sap_Flow(0,c+l+1));
    }
    return 0;
}
