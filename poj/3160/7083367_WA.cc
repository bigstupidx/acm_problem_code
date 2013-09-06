#include<iostream>
#include<vector>
#include <cstring>
#include <cstdio>
#include<algorithm>
using namespace std;
const int size = 30003;

vector<int> Graph[size], graph2[size];
vector<int> US, VS;
int Val[size], val2[size];

int N, M, SCC;
int numb[size], belg[size], in[size];
bool flag[size];

void Init() {
    int i, u, v;
    for (i = 0; i < N; i++) {
	graph2[i].clear();
	Graph[i].clear();
    }
    US.clear(), VS.clear();
    for (i = 0; i < N; i++) {
	scanf("%d", &Val[i]);
	if(Val[i]<0)Val[i]=0;
    }
    for (i = 0; i < M; i++) {
	scanf("%d %d", &u, &v);
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
	if (!flag[i]) {
	    dfs2(i);
	    SCC++;
	}
}

void Newgraph() {
    int i, u, v;
    for (i = 0; i < N; i++)
	graph2[i].clear();

    memset(in, 0, sizeof (in));
    for (i = 0; i < M; i++) {
	u = belg[US[i]];
	v = belg[VS[i]];
	if (u != v) {
	    graph2[u].push_back(v);
	    in[v]++;
	}
    }
    memset(val2, 0, sizeof (val2));
    for (i = 0; i < SCC; i++)
	val2[belg[i]] += Val[i];
}
int ans, tmp, dp[size];

int Dfs(int u) {
    if (flag[u])return dp[u];
    flag[u] = 1;
    int temp = 0;
    for (int v = graph2[u].size() - 1; v >= 0; v--) {
	int tp = Dfs(graph2[u][v]);
	temp = temp > tp ? temp : tp;
    }
    return dp[u] = val2[u] + temp;
}

int main() {
    while (scanf("%d%d", &N, &M) != EOF) {
	Init();
	Kosaraju();
	Newgraph();
	ans = tmp = 0;
	memset(flag, 0, sizeof (flag));
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < SCC; i++) {
	    if (in[i] == 0) {
		tmp = Dfs(i);
		ans = tmp > ans ? tmp : ans;
	    }
	}
	printf("%d\n", ans);
    }
    return 0;
}
