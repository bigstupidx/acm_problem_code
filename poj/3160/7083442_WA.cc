#include<iostream>
#include<vector>
#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;
const int size = 30003;

vector<int> Graph[size], graph2[size];
vector<int> US, VS;
int Val[size], val2[size];

int N, M, SCC;
int numb[size], belg[size];
bool flag[size];

void Init()
{
     int i, u, v;
     for (i = 0; i < N; i++)
     {
         graph2[i].clear();
         Graph[i].clear();
     }
     US.clear(), VS.clear();
     for (i = 0; i < N; i++)
     {
         scanf("%d",&Val[i]);
         if (Val[i] < 0) Val[i] = 0;
     }
     for (i = 0; i < M; i++)
     {
         scanf("%d %d",&u,&v);
         Graph[u].push_back(v);
         graph2[v].push_back(u);
         US.push_back(u);
         VS.push_back(v);
     }
}
void dfs1(int cur) {
    flag[cur] = 1;
    for (int i = 0; i < Graph[cur].size(); i++)
	if (!flag[Graph[cur][i]]) dfs1(Graph[cur][i]);
    numb[SCC++] = cur;
}

void dfs2(int cur) {
    flag[cur] = 1;
    belg[cur] = SCC;
    for (int i = 0; i < graph2[cur].size(); i++)
	if (!flag[graph2[cur][i]]) dfs2(graph2[cur][i]);
}

void Kosaraju() {
    int i;
    memset(flag, 0, sizeof (flag));
    for (i = SCC = 0; i < N; i++)
	if (!flag[i]) dfs1(i);
    SCC=0;
    memset(flag, 0, sizeof (flag));
    for (i = N-1; i>=0; i--)
	if (!flag[numb[i]]) {
	    dfs2(numb[i]);
	    SCC++;
	}
}

void Newgraph()
{
     int i, u, v;
     for (i = 0; i < N; i++)
     graph2[i].clear();

     for (i = 0; i < M; i++)
     {
         u = belg[US[i]];
         v = belg[VS[i]];
         if (u != v)
            graph2[u].push_back(v);
     }
     memset(val2,0,sizeof(val2));
     for (i = 0; i < N; i++)
     val2[belg[i]] += Val[i];
}
int ans, tmp, dp[size];
void Dfs(int u)
{
     flag[u] = 1;
     for (int v = graph2[u].size()-1; v >= 0; v--)
         if (!flag[graph2[u][v]]) Dfs(graph2[u][v]);
     belg[tmp++] = u;
}

int main()
{
    int i, u, v;
    while (scanf("%d%d",&N,&M)!=EOF)
    {
          Init();
          Kosaraju();
          Newgraph();
          ans = tmp = 0;
          memset(flag,0,sizeof(flag));
          for (i = 0; i < SCC; i++)
          if (!flag[i]) Dfs(i);
          for (i = 0; i < SCC; i++)
          {
              u = belg[i];
              dp[u] = val2[u];
              tmp = 0;
              for (v = graph2[u].size()-1; v >= 0; v--)
              tmp = max(tmp, val2[graph2[u][v]]);
              dp[u] += tmp;
          }
          for (i = 0; i < SCC; i++) ans = (ans<dp[i])?dp[i]:ans;
          printf("%d\n",ans);
    }
    return 0;
}