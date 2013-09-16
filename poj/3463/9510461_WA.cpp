#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define maxn 1010
#define maxm 20010
#define inf 1000000000
using namespace std;

int n, m;

struct edg
{
    int to, dis;
    edg *next;
}edge[maxm], *vert[maxn];

void Add_Edge(int u, int v, int w, int &top)
{
    edg *p = &edge[++top];
    p->dis = w, p->to = v;
    p->next = vert[u];
    vert[u] = p;
}

struct node
{
    int u, dis;

    bool operator < (const node &x) const
    {
        return dis > x.dis;
    }
};

int dist[maxn];
int cnt[maxn], cntless[maxn];
bool mark[maxn];
priority_queue<node> Q;

void Dijkstra(int s)
{
    while(!Q.empty()) Q.pop();
    memset(cnt, 0, sizeof(cnt));
    memset(cntless, 0, sizeof(cntless));
    for(int i = 1; i <= n; ++i) dist[i] = inf, mark[i] = 0;
    dist[s] = 0;
    cnt[s] = 1;
    node ft, ps;
    ft.dis = 0, ft.u = s;
    Q.push(ft);
    for(int i = 1; i < n; ++i)
    {
        int k;
        do
        {
            if(Q.empty()) break;
            ft = Q.top();
            Q.pop();
            k = ft.u;
        } while(mark[k]);
        mark[k] = 1;
        for(edg *p = vert[k]; p; p = p->next)
        {
            if(mark[p->to]) continue;
            if(dist[p->to] > dist[k] + p->dis)
            {
                if(dist[p->to] == dist[k] + p->dis + 1)
                {
                    cntless[p->to] = cnt[p->to] + cntless[k];
                    cnt[p->to] = cnt[k];
                }
                else
                {
                    cnt[p->to] = cnt[k];
                    cntless[p->to] = cntless[k];
                }
                dist[p->to] = dist[k] + p->dis;
                ps.dis = dist[p->to], ps.u = p->to;
                Q.push(ps);
            }
            else if(dist[p->to] + 1 == dist[k] + p->dis)
            {
                cntless[p->to] += cnt[k];
            }
            else if(dist[p->to] == dist[k] + p->dis)
            {
                cnt[p->to] += cnt[k];
                cntless[p->to] += cntless[k];
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int top = -1;
        memset(vert, 0, sizeof(vert));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++i)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            Add_Edge(a, b, c, top);
        }
        int src, des;
        scanf("%d%d", &src, &des);
        Dijkstra(src);
        printf("%d\n", cnt[des] + cntless[des]);
    }
    return 0;
}
/*
1
5 8
1 2 3
1 3 2
1 4 4
2 3 1
2 5 3
3 4 2
3 5 4
4 5 3
1 5
*/

