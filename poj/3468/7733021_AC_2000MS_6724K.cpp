#include <cstdio>
#include <cstring>
#define maxn 100010

using namespace std;

struct segTree {
	int l, r;
	long long c, sum;
} t[4 * maxn];

int n, m, val[maxn];

void create(int cur, int lf, int rt) {
	if (rt < lf)return;
	t[cur].l = lf, t[cur].r = rt, t[cur].c = 0;
	if (rt == lf) {
		t[cur].sum = val[lf];
		return;
	}
	create(cur * 2, lf, (lf + rt) / 2);
	create(cur * 2 + 1, (lf + rt) / 2 + 1, rt);
	t[cur].sum = t[cur * 2].sum + t[cur * 2 + 1].sum;
}

void downdata(int cur) {
	t[cur * 2].c += t[cur].c;
	t[cur * 2].sum += t[cur].c * (t[cur * 2].r - t[cur * 2].l + 1);
	t[cur * 2 + 1].c += t[cur].c;
	t[cur * 2 + 1].sum += t[cur].c * (t[cur * 2 + 1].r - t[cur * 2 + 1].l + 1);
	t[cur].c = 0;
}

void change(int cur, int lf, int rt, int d) {
	if (t[cur].l > rt || t[cur].r < lf)return;
	if (t[cur].l >= lf && t[cur].r <= rt) {
		t[cur].c += d;
		t[cur].sum += d * (t[cur].r - t[cur].l + 1);
		return;
	}
	if (t[cur].c)downdata(cur);
	change(cur * 2, lf, rt, d);
	change(cur * 2 + 1, lf, rt, d);
	t[cur].sum = t[cur * 2].sum + t[cur * 2 + 1].sum;
}

long long get_sum(int cur, int lf, int rt) {
	if (t[cur].l > rt || t[cur].r < lf)return 0;
	if (t[cur].l >= lf && t[cur].r <= rt)return t[cur].sum;
	downdata(cur);
	return get_sum(cur * 2, lf, rt) + get_sum(cur * 2 + 1, lf, rt);
}

char str[3];

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", val + i);
		}
		create(1, 1, n);
		for (int lf, rt, d, i = 0; i < m; i++) {
			scanf("%s", str);
			scanf("%d%d", &lf, &rt);
			if (str[0] == 'Q') {
				printf("%lld\n", get_sum(1, lf, rt));
			}
			else {
				scanf("%d", &d);
				change(1, lf, rt, d);
			}
		}
	}
	return 0;
}
