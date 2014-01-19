#include <cstdio>
#include <set>
#include <cstring>
#define maxn 20012

using namespace std;

struct segTree {
	int l, r, c;
} t[4 * maxn];

int id[10000010];
bool v[maxn];

struct node {
	int x, y;
} nod[10010];

void create(int cur, int lf, int rt) {
	if (lf > rt)return;
	t[cur].l = lf, t[cur].r = rt, t[cur].c = 0;
	if (lf == rt)return;
	create(cur * 2, lf, (lf + rt) / 2);
	create(cur * 2 + 1, (lf + rt) / 2 + 1, rt);
}

void downdata(int cur) {
	t[cur * 2].c = t[cur].c;
	t[cur * 2 + 1].c = t[cur].c;
	t[cur].c = 0;
}

void change(int cur, int lf, int rt, int x) {
	if (t[cur].l > rt || t[cur].r < lf)return;
	if (t[cur].l >= lf && t[cur].r <= rt) {
		t[cur].c = x;
		return;
	}
	if (t[cur].c)downdata(cur);
	change(cur * 2, lf, rt, x);
	change(cur * 2 + 1, lf, rt, x);
}

void get_sum(int cur, int lf, int rt) {
	if (t[cur].l > rt || t[cur].r < lf)return;
	if (t[cur].c) {
		v[t[cur].c] = 1;
		return;
	}
	get_sum(2 * cur, lf, rt);
	get_sum(2 * cur + 1, lf, rt);
}

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		int n;
		scanf("%d", &n);
		set <int> st;
		set <int> ::iterator p;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &nod[i].x, &nod[i].y);
			st.insert(nod[i].x);
			st.insert(nod[i].y);
		}
		int xx = 0, ans = 0;
		for (p = st.begin(); p != st.end(); ++p) {
			id[*p] = ++xx;
		}
		create(1, 1, xx);
		for (int i = 0; i < n; i++) {
			change(1, id[nod[i].x], id[nod[i].y], i + 1);
		}
		memset(v, 0, sizeof (v));
		get_sum(1, 1, xx);
		for (int i = 1; i <= xx; i++) {
			if (v[i])++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
