#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

struct Qnode {
	int u, v;

	bool operator<(const Qnode & a)const {
		return a.v < v;
	}
} now;

inline int ABS(int x) {
	return x > 0 ? x : -x;
}

int solve() {
	priority_queue <Qnode> Q;
	for (int u, i = 0; i < n; i++) {
		scanf("%d", &u);
		now.u = u;
		now.v = ABS(u);
		Q.push(now);
	}
	int cnt = 0, xcur = 0;
	while (m >= 0 && !Q.empty()) {
		now = Q.top();
		Q.pop();
		int d = ABS(xcur - now.u);
		if (m - d < 0)break;
		++cnt;
		m -= d;
		xcur = now.u;
	}
	return cnt;
}

int main() {
	while (scanf("%d%d", &m, &n) != EOF) {
		printf("%d\n", solve());
	}
	return 0;
}
