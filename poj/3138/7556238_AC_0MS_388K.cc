#include <cstdio>
#include <cstring>

int n, m, k, flag[102], cnt[102];

int main() {
	int nca = 1;
	while (scanf("%d%d%d", &n, &m, &k), n || m || k) {
		memset(flag, 0, sizeof (flag));
		for (int i = 0; i < n; i++) {
			int id, p, q;
			scanf("%d%d%d", &id, &p, &q);
			cnt[id] = p + q;
		}
		for (int i = 0; i < m; i++) {
			int id, x;
			scanf("%d%d", &id, &x);
			if (x >= k)flag[id] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += cnt[i] + flag[i];
		}
		printf("Case %d: %d\n", nca++, ans);
	}
	return 0;
}
