#include <cstdio>
#include <cstring>
#define maxn 100010

using namespace std;

struct segTree {
	int l, r, c;
	int sum;
} t[3 * maxn];

int n, m, T;

void create(int cur, int lf, int rt) {
	if (rt < lf)return;
	t[cur].l = lf, t[cur].r = rt, t[cur].c = 0, t[cur].sum = 2;
	if (lf == rt) {
		return;
	}
	create(cur * 2, lf, (lf + rt) / 2);
	create(cur * 2 + 1, (lf + rt) / 2 + 1, rt);
}

void downdata(int cur) {
	t[cur * 2].c = t[cur].c;
	t[cur * 2].sum = t[cur].c;
	t[cur * 2 + 1].c = t[cur].c;
	t[cur * 2 + 1].sum = t[cur].c;
	t[cur].c = 0;
}

void change(int cur, int lf, int rt, int d) {
	if (t[cur].l > rt || t[cur].r < lf)return;
	if (t[cur].l >= lf && t[cur].r <= rt) {
		t[cur].c = 1 << d;
		t[cur].sum = 1 << d;
		return;
	}
	if (t[cur].c)downdata(cur);
	change(cur * 2, lf, rt, d);
	change(cur * 2 + 1, lf, rt, d);
	t[cur].sum = t[cur * 2].sum | t[cur * 2 + 1].sum;
}

int get_sum(int cur, int lf, int rt) {
	if (t[cur].l > rt || t[cur].r < lf)return 0;
	if (t[cur].l >= lf && t[cur].r <= rt)return t[cur].sum;
	if (t[cur].c)downdata(cur);
	return get_sum(cur * 2, lf, rt) | get_sum(cur * 2 + 1, lf, rt);
}

char str[3];

int main() {
	while (scanf("%d%d%d", &n, &T, &m) != EOF) {
		create(1, 1, n);
		for (int a, b, c, d, i = 0; i < m; i++) {
			scanf("%s%d%d", str, &a, &b);
			if (a > b) {
				d = a, a = b, b = d;
			}
			if (str[0] == 'C') {
				scanf("%d", &c);
				change(1, a, b, c);
			}
			else {
				int temp = get_sum(1, a, b), cnt = 0;
				for (int i = 1; i <= T; i++) {
					if (temp & (1 << i)) {
						++cnt;
					}
				}
				printf("%d\n", cnt);
			}
		}
	}
	return 0;
}
