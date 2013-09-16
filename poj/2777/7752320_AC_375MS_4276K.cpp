#include <cstdio>
#include <cstring>
#define maxn 100010

using namespace std;

struct edge {
	int l, r, c, sum;
} t[maxn * 3];

int n, m, p;
char str[3];

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
	t[cur * 2].sum = t[cur].sum;
	t[cur * 2 + 1].c = t[cur].c;
	t[cur * 2 + 1].sum = t[cur].sum;
	t[cur].c = 0;
}

void change(int cur, int lf, int rt, int d) {
	if (t[cur].l > rt || t[cur].r < lf)return;
	if (t[cur].l >= lf && t[cur].r <= rt) {
		t[cur].c = 1;
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

int main() {
	while (scanf("%d%d%d", &n, &m, &p) != EOF) {
		create(1, 1, n);
		for (int i = 0; i < p; i++) {
			int lf, rt, d;
			scanf("%s%d%d", str, &lf, &rt);
			if (lf > rt) {
				d = lf, lf = rt, rt = d;
			}
			if (str[0] == 'C') {
				scanf("%d", &d);
				change(1, lf, rt, d);
			}
			else if (str[0] == 'P') {
				int sum = get_sum(1, lf, rt), cnt = 0;
				for (int i = 1; i <= m; i++) {
					if (sum & (1 << i)) {
						++cnt;
					}
				}
				printf("%d\n", cnt);
			}
		}
	}
	return 0;
}
