#include <cstdio>
#include <cstring>

struct node {
	int s[4];

	inline bool inside(int i) const {
		return s[i / 32]&(1 << (i % 32));
	}

	inline void add(int i) {
		s[i / 32] |= (1 << (i % 32));
	}
} lin[130], ans[1010];

int n, m, top, que[1010];

node operator &(const node &a, const node &b) {
	node c;
	c.s[0] = a.s[0] & b.s[0];
	c.s[1] = a.s[1] & b.s[1];
	c.s[2] = a.s[2] & b.s[2];
	c.s[3] = a.s[3] & b.s[3];
	return c;
}

bool operator ==(const node &a, const node &b) {
	if (a.s[0] == b.s[0] && a.s[1] == b.s[1]) {
		if (a.s[2] == b.s[2] && a.s[3] == b.s[3]) {
			return true;
		}
		return false;
	}
	return false;
}

bool ok(int k, int tot, const node &a) {
	for (int i = 0; i < k; i++) {
		if (!a.inside(i) && a == (a & lin[i])) {
			return false;
		}
	}
	for (int i = 0; i < tot; i++) {
		if (a == ans[que[i]]) {
			return false;
		}
	}
	return true;
}

void solve() {
	top = 1;
	ans[0].s[0] = 1;
	for (int i = 1; i < n && top <= 1000; i++) {
		int mm = top, tot = 0;
		for (int j = 0; j < mm && top <= 1000; j++) {
			node now = ans[j] & lin[i];
			if (now == ans[j]) {
				que[tot++] = j;
				ans[j].add(i);
			}
			else {
				now.add(i);
				if (ok(i, tot, now)) {
					ans[top] = now;
					que[tot++] = top++;
				}
			}
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(lin, 0, sizeof (lin));
		memset(ans, 0, sizeof (ans));
		for (int x, y, i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			x--, y--;
			lin[x].add(y);
			lin[y].add(x);
		}
		solve();
		if (top > 1000)
			puts("Too many maximal sets of friends.");
		else
			printf("%d\n", top);
	}
	return 0;
}
