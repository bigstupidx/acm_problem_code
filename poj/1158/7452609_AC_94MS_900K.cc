#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>
#define maxn 302

using namespace std;

struct edge {
	int to;
	int d;
	edge *next;
} edg[30010], *vert[maxn];

const int inf = 2147483647;
int n, m, dis[maxn], mark[maxn], pre[maxn];

struct QN {
	int u;
	int d;
	bool operator<(const QN & a)const {
		return a.d < d;
	}
} now;

struct node {
	int color, c, t1, t2;
} nod[maxn];

int get_time(int j, int k, int start) {
	int color1, color2, t1, t2;
	if (nod[j].color == 0) {
		t1 = nod[j].t1 - nod[j].c + start;
	}
	else t1 = nod[j].t2 - nod[j].c + nod[j].t1 + start;

	if (nod[k].color == 0) {
		t2 = nod[k].t1 - nod[k].c + start;
	}
	else t2 = nod[k].t2 - nod[k].c + nod[k].t1 + start;

	t1 %= (nod[j].t1 + nod[j].t2);
	t2 %= (nod[k].t1 + nod[k].t2);

	if (t1 < nod[j].t1)
		color1 = 0;
	else
		color1 = 1;
	if (t2 < nod[k].t1)
		color2 = 0;
	else
		color2 = 1;

	if (color1 == color2)return start;
	for (int i = 0; i < 10; i++) {
		int temp;
		if (color1 == 0) {
			temp = nod[j].t1 - t1;
		}
		else
			temp = nod[j].t1 + nod[j].t2 - t1;

		if (color2 == 0) {
			if (temp > nod[k].t1 - t2) {
				temp = nod[k].t1 - t2;
			}
		}
		else {
			if (temp > nod[k].t1 + nod[k].t2 - t2) {
				temp = nod[k].t1 + nod[k].t2 - t2;
			}
		}

		t1 = (t1 + temp) % (nod[j].t1 + nod[j].t2);
		t2 = (t2 + temp) % (nod[k].t1 + nod[k].t2);

		if (t1 < nod[j].t1)
			color1 = 0;
		else
			color1 = 1;
		if (t2 < nod[k].t1)
			color2 = 0;
		else
			color2 = 1;
		start += temp;
		if (color1 == color2)return start;
	}
	return -1;
}

void add_edge(int x, int y, int va, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->d = va;
	p->next = vert[x];	vert[x] = p;
}

void dijkstra(int s, int t) {
	priority_queue <QN> Q;
	for (int i = 1; i <= n; i++) {
		dis[i] = inf;
		mark[i] = 0;
	}
	now.u = s;
	Q.push(now);
	dis[s] = 0;
	for (int k, i = 1; i < n; i++) {
		do {
			if (Q.empty())return;
			now = Q.top();
			Q.pop();
			k = now.u;
		} while (mark[k]);
		if (k == t)return;
		mark[k] = 1;
		for (edge *p = vert[k]; p; p = p->next) {
			if (mark[p->to])continue;
			int tim = get_time(k, p->to, dis[k]);
			if (tim != -1 && dis[p->to] > tim + p->d) {
				dis[p->to] = tim + p->d;
				now.u = p->to;
				now.d = dis[p->to];
				Q.push(now);
			}
		}
	}
}

char str[3];

int main() {
	//freopen("in.txt", "r", stdin);
	int s, t;
	scanf("%d%d", &s, &t);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		scanf("%d%d%d", &nod[i].c, &nod[i].t1, &nod[i].t2);
		if (str[0] == 'B') {
			nod[i].color = 0;
		}
		else {
			nod[i].color = 1;
		}
	}
	int top = -1;
	for (int i = 0; i < m; i++) {
		int u, v, va;
		scanf("%d%d%d", &u, &v, &va);
		add_edge(u, v, va, top);
		add_edge(v, u, va, top);
	}
	dijkstra(s, t);

//	for (int i = 1; i <= n; i++) {
//		printf("%d ", dis[i]);
//	}
//	puts("");
	if (dis[t] == inf)
		puts("0");
	else
		printf("%d\n", dis[t]);
	return 0;
}
