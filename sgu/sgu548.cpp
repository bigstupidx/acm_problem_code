#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int n, aa[200010], bb[200010], ans[2000010];
char str[3];

struct Qnode {
	int u;
	int i;
	bool operator<(const Qnode &a) const {
		return a.u < u;
	}
} now;

void solve() {
	priority_queue<Qnode> Q;
	for (int i = 1; i < n - 1; i++) {
		if (aa[i] == 1) {
			now.u = bb[i];
			now.i = i;
			Q.push(now);
		} else {
			while (!Q.empty() && Q.size() >= bb[i]) {
				Q.pop();
			}
		}
	}
	if (Q.size() < bb[n - 1]) {
		puts("-1");
	} else {
		int sum = 0, top = 0;
		while (!Q.empty()) {
			now = Q.top();
			Q.pop();
			sum += now.u;
			ans[top++] = now.i + 1;
		}
		sort(ans, ans + top);
		printf("%d\n%d\n%d", sum, top, ans[0]);
		for (int i = 1; i < top; i++) {
			printf(" %d", ans[i]);
		}
		puts("");
	}
}

int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i < n; i++) {
			scanf("%s%d", str, &bb[i]);
			if (str[0] == 'p') {
				aa[i] = 0;
			} else {
				aa[i] = 1;
			}
		}
		solve();
	}
	return 0;
}
