#include <cstdio>
#include <queue>
#include <cstring>

#define INF 1000000000
#define MOD 100000

struct Node
{
    int to, d;
    Node *next;
} e[1002], *vert[102];

int n, m, dis[102];
bool mark[102];

void add_edge(int u, int v, int d, int &top)
{
    Node *p = &e[top++];
    p->to = v;
    p->d = d;
    p->next = vert[u], vert[u] = p;

    p = &e[top++];
    p->to = u;
    p->d = d;
    p->next = vert[v], vert[v] = p;
}

struct Qnode
{
    int u;
    int d;
    bool operator <(const Qnode &a)const
    {
        return a.d < d;
    }
} now;

void dijstra(int s)
{
    memset(mark, 0, sizeof(mark));

    for (int i = 0; i < n; i++)
    {
        dis[i] = INF;
    }

    std::priority_queue<Qnode>Q;
    now.u = s;
    now.d = 0;
    dis[s] = 0;
    Q.push(now);

    for (int k, i = 1; i < n; i++)
    {
        do
        {
            now = Q.top();
            Q.pop();
            k = now.u;
        }
        while (mark[k]);

        mark[k] = true;

        for (Node *p = vert[k]; p; p = p->next)
        {
            if (!mark[p->to] && dis[p->to] > dis[k] + p->d)
            {
                dis[p->to] = dis[k] + p->d;
                now.u = p->to;
                now.d = dis[p->to];
                Q.push(now);
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    int fic = 1, top = 0;

    for (int u, v, d, i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        fic = i == 0 ? 1 : (fic * 2 % MOD);
        add_edge(u, v, fic, top);
    }

    dijstra(0);

    for (int i = 1; i < n; i++)
    {
        if (dis[i] == INF)
        {
            puts("-1");
        }
        else
        {
            printf("%d\n", dis[i] % MOD);
        }
    }

    return 0;
}
