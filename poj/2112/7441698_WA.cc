#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define MAXN 250
#define INF 2147483647

using namespace std;

int N;
int K, C, M;

int pre[MAXN];
int c[MAXN][MAXN];
int g[MAXN][MAXN];

int Ford_Fulkerson(int src, int des)
{
    int flow=0;

    while(1)
    {
        queue <int> Q;
        int mini=INF;
        memset(pre, -1, sizeof(pre));
        Q.push(src);
        while(!Q.empty() && pre[des]==-1)
        {
            int i = Q.front(); Q.pop();
            for(int j=0; j<N; j++)
                if(pre[j]==-1 && c[i][j]>0)
                {
                    pre[j] = i;
                    Q.push(j);
                }
        }
        if(pre[des] == -1) return flow;
        for(int i=des; i!=src; i=pre[i])
            if(mini > c[pre[i]][i])
                mini = c[pre[i]][i];
        flow += mini;
        for(int i=des; i!=src; i=pre[i])
        {
            c[pre[i]][i] -= mini;
            c[i][pre[i]] += mini;
        }
    }
}

void init(void)
{
    scanf("%d%d%d", &K, &C, &M);
    N = K + C + 1;

    for(int i=1; i<N; i++)
        for(int j=1; j<N; j++)
        {
            scanf("%d", &g[i][j]);
            if(!g[i][j]) g[i][j] = INF;
        }

    for(int k=1; k<N; k++)
        for(int i=1; i<N; i++)
            for(int j=1; j<N; j++)
                if(g[i][k] < INF && g[k][j] < INF)
                {
                    int tmp=g[i][k] + g[k][j];
                    if(tmp < g[i][j]) g[i][j] = tmp;
                }

    int maxd = 0;
    for(int i=K+1; i<N; i++)
        for(int j=1; j<=K; j++)
            if(g[i][j]!=INF&&maxd < g[i][j])
                maxd = g[i][j];

    int st=0, ed=maxd, mid;

    while(st <= ed)
    {
        mid = (st + ed) / 2;
        for(int i=1; i<=K; i++)
            c[i][0] = M;
        for(int i=K+1; i<N; i++)
            c[N][i] = 1;
        for(int i=K+1; i<N; i++)
            for(int j=1; j<=K; j++)
            {
                if(g[i][j] <= mid) c[i][j] = 1;
                else c[i][j] = 0;
            }
        if(Ford_Fulkerson(N, 0) == C) ed = mid - 1;
        else st = mid + 1;
    }
    printf("%d\n", st);
}

int main()
{
    init();
    return 0;
}