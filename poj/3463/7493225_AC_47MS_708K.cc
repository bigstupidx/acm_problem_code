#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define MAXN 1000
#define MAXM 10000
#define INF 2147483647

using namespace std;

struct node{
    int to, d;
    node *next;
}e[MAXM], *vert[MAXN+1];

struct Qnode{
    int u, d;
    bool operator<(const Qnode &a)const{
        return a.d < d;
    }
};

int N, M, mindis;
int dist[MAXN+1], count[MAXN+1], count_1[MAXN+1];
bool mark[MAXN+1];

void Add_Edge(int u, int v, int va, int &top)
{
    node *p = &e[++top];
    p->to = v; p->d = va; p->next = vert[u]; vert[u] = p;
}

void dijkstra(int st, int ed)
{
    priority_queue <Qnode> Q, Q2;
    memset(count, 0, sizeof(count));
    memset(count_1, 0, sizeof(count_1));
    for(int i=1; i<=N; i++)
    {
        dist[i] = INF;
        mark[i] = false;
    }
    dist[st] = 0; count[st] = 1;
    Qnode a;
    a.u = st; a.d = 0;  Q.push(a);
    for(int i=1; i<=N; i++)
    {
        while(true)
        {
            if(Q.empty())  return;
            a = Q.top(); Q.pop();
            if(!mark[a.u]) break;
        }
        int u = a.u;
        mark[u] = true;
        while(!Q.empty())
        {
            a = Q.top();
            if(a.d == dist[u] && !mark[a.u])
            {
                Q2.push(a);
                Q.pop();
            }
            else break;
        }
        while(!Q2.empty())
        {
            a = Q2.top(); Q2.pop(); Q.push(a);
            node *p = vert[a.u];
            while(p != NULL)
            {
                if(p->to == u)
                {
                    int tmp = a.d + p->d;
                    if(tmp == dist[u] + 1) count_1[u] += count[a.u];
                }
                p = p->next;
            }
        }
        if(mark[ed]) break;
        node *p = vert[u];
        while(p != NULL)
        {
            int tmp = dist[u] + p->d;
            if(!mark[p->to])
            {
                if(tmp < dist[p->to])
                {
                    if(tmp + 1 == dist[p->to]) count_1[p->to] = count[p->to];
                    else count_1[p->to] = 0; //!!!!
                    count[p->to] = count[u];
                    count_1[p->to] += count_1[u];
                    dist[p->to] = tmp;
                    a.d = tmp; a.u = p->to; Q.push(a);
                }
                else
                {
                    if(tmp == dist[p->to])
                    {
                        count[p->to] += count[u];
                        count_1[p->to] += count_1[u];
                    }
                    if(tmp == dist[p->to] + 1) count_1[p->to] += count[u];
                }
            }
            p = p->next;
        }
    }
}

void init(void)
{
    int cases;

    scanf("%d", &cases);
    while(cases--)
    {
        int top=-1, st, ed;
        scanf("%d%d", &N, &M);
        memset(vert, 0, sizeof(vert));
        for(int i=0; i<M; i++)
        {
            int u, v, va;
            scanf("%d%d%d", &u, &v, &va);
            Add_Edge(u, v, va, top);
        }
        scanf("%d%d", &st, &ed);
        dijkstra(st, ed);
        printf("%d\n", count[ed]+count_1[ed]);
    }
}

int main()
{
    init();
    return 0;
}
