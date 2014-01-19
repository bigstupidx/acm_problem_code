#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
	int s, t, e;

	bool operator<(const node & a)const {
		return a.t > t;
	}
} nod[1002];

int n, m, r, ans[1002];

int main() {
	while (scanf("%d%d%d", &n, &m, &r) != EOF) {
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &nod[i].s, &nod[i].t, &nod[i].e);
			nod[i].t += r;
		}
		sort(nod, nod + m);
		ans[0] = nod[0].e;
		for (int i = 1; i < m; i++) {
			ans[i] = nod[i].e;
			for (int j = 0; j < i; j++) {
				if (nod[j].t <= nod[i].s) {
					ans[i] = max(ans[j] + nod[i].e, ans[i]);
				}
				else {
					ans[i] = max(ans[j], ans[i]);
				}
			}
		}
		printf("%d\n", ans[m - 1]);
	}
	return 0;
}
