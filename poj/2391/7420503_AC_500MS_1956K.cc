#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define maxn 404

using namespace std;

struct edge {
	int to, c, next;
} e[1000010];

int n, m, head[maxn], p[maxn][2], L[maxn], va[202][2];

long long inf = 1, dis[202][202], que[40010];

void add_edge(int x, int y, int va, int &top) {
	//printf("%d -> %d %d\n", x, y, va);
	e[++top].to = y;
	e[top].c = va;
	e[top].next = head[x];
	head[x] = top;

	e[++top].to = x;
	e[top].c = 0;
	e[top].next = head[y];
	head[y] = top;
}

int max_flow(int s, int t) {
	int flow = 0;
	while (1) {
		queue<int>Q;
		memset(L, -1, sizeof (L));
		Q.push(s);
		L[s] = 0;
		while (!Q.empty()) {
			int i = Q.front();
			Q.pop();
			for (int j = head[i]; j != -1; j = e[j].next) {
				if (L[e[j].to] == -1 && e[j].c > 0) {
					L[e[j].to] = L[i] + 1;
					Q.push(e[j].to);
				}
			}
		}
		if (L[t] == -1) {
			//printf("flow : %d\n", flow);
			return flow;
		}
		int top = 0;
		p[0][0] = s;
		p[0][1] = head[s];
		while (top >= 0) {
			if (p[top][0] != t) {
				while (p[top][1] >= 0) {
					int j = p[top][1];
					if (L[e[j].to] > L[p[top][0]] && e[j].c > 0) {
						p[top + 1][0] = e[j].to;
						p[top + 1][1] = head[e[j].to];
						top++;
						break;
					}
					p[top][1] = e[j].next;
				}
				if (p[top][1] < 0) {
					if (--top < 0)break;
					p[top][1] = e[p[top][1]].next;
				}
			}
			else {
				int mini = 100000000, k;
				for (int i = 0; i < top; i++) {
					if (mini > e[p[i][1]].c) {
						mini = e[p[i][1]].c;
						k = i;
					}
				}
				flow += mini;
				for (int i = 0; i < top; i++) {
					e[p[i][1]].c -= mini;
					e[p[i][1]^1].c += mini;
				}
				top = k;
				p[top][1] = e[p[top][1]].next;
			}
		}
	}
}

void build_g(long long mid) {
	int top = -1, t = 2 * n + 1;
	memset(head, -1, sizeof (head));
	for (int i = 1; i <= n; i++) {
		add_edge(i, i+n, 100000000, top);
		if (va[i][0])add_edge(0, i, va[i][0], top);
		if (va[i][1])add_edge(i + n, t, va[i][1], top);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (dis[i][j] != inf && dis[i][j] <= mid) {
				add_edge(i, j + n, 100000000, top);
				add_edge(j, i + n, 100000000, top);
			}
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	inf <<= 60;
	//printf("%lld\n", inf);
	while (scanf("%d%d", &n, &m) != EOF) {
		int sum1 = 0, sum2 = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 2; j++) {
				scanf("%d", &va[i][j]);
				j == 0 ? sum1 += va[i][0] : sum2 += va[i][1];
			}
			for (int j = 1; j <= n; j++) {
				dis[i][j] = inf;
			}
			dis[i][i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int u, v, va;
			scanf("%d%d%d", &u, &v, &va);
			if (dis[u][v] > va) {
				dis[u][v] = va;
				dis[v][u] = va;
			}
		}
		if (sum1 > sum2) {
			puts("-1");
			continue;
		}
		for (int w = 1; w <= n; w++) {
			for (int u = 1; u <= n; u++) {
				if (dis[u][w] == inf)continue;
				for (int v = 1; v <= n; v++) {
					if (dis[w][v] == inf)continue;
					if (dis[u][v] > dis[u][w] + dis[w][v]) {
						dis[u][v] = dis[u][w] + dis[w][v];
					}
				}
			}
		}
		set <long long> st;
		vector <long long> temp;
		st.insert(0);
		temp.push_back(0);
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (dis[i][j] != inf) {
					if (st.find(dis[i][j]) == st.end()) {
						st.insert(dis[i][j]);
						temp.push_back(dis[i][j]);
					}
				}
			}
		}
		sort(temp.begin(), temp.end());
		int lf = 0, rt = temp.size() - 1;
		while (lf <= rt) {
			int mid = (lf + rt) / 2;
			build_g(temp[mid]);
			//printf("try %d ", temp[mid]);
			if (max_flow(0, 2 * n + 1) == sum1) {
				rt = mid - 1;
			}
			else lf = mid + 1;
		}
		if (lf == temp.size())puts("-1");
		else printf("%I64d\n", temp[lf]);
	}
	return 0;
}
