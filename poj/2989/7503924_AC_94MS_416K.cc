#include <cstdio>
#include <cstring>

using namespace std;

struct node {
	int s[4];

	inline bool inside(int i) {
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
	}
	return false;
}

bool ok(node &a, int k, int tot) {
	/*判断a是否是极大团
	根据极大团的定义有：
	若a为极大团则对于不在集合内的一点i，必定不能与集合内所有点都有边相连*/
	for (int i = 0; i < k; i++) {
		if (!a.inside(i) && a == (a & lin[i])) {
			return false;
		}
	}
	/*判重，如1 3产生3 5，若2 3与5再产生3 5*/
	for (int i = 0; i < tot; i++) {
		if (ans[que[i]] == a)return false;
	}
	return true;
}

void solve() {
	ans[0].s[0] = 1;
	for (int i = 1; i < n && top <= 1000; i++) {
		int tot = 0, m = top;
		for (int j = 0; j < m && top <= 1000; j++) {
			node now = lin[i] & ans[j];
			//printf("%d ", now.s[0]);
			if (now == ans[j]) {
				que[tot++] = j;
				ans[j].add(i);
			}
			else {
				now.add(i);
				if (ok(now, i, tot)) {
					ans[top] = now;
					que[tot++] = top++;
				}
			}
		}
		//puts("");
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d%d", &n, &m) != EOF) {
		top = 1;
		memset(ans, 0, sizeof (ans));
		memset(lin, 0, sizeof (lin));
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
