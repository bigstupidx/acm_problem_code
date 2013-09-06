#include <cstdio>
#include <cstring>

using namespace std;

int n, m, cnt[5010], xx[5010], yy[5010], y1, y2, x1, x2;

bool leftOfStick(int yyy1, int yyy2, int x, int y) {
	int ax = yyy1 - yyy2;
	int ay = y1 - y2;
	int bx = x - yyy2;
	int by = y - y2;
	if (ax * by - ay * bx > 0)
		return true;
	return false;
}

int main() {
	bool first = false;
	while (scanf("%d", &n), n) {
		scanf("%d%d%d%d%d", &m, &x1, &y1, &x2, &y2);
		if (!first) {
			first = true;
		} else {
			puts("");
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			scanf("%d%d", xx + i, yy + i);
		}
		for (int i = 0; i < m; i++) {
			int x, y, k = 0, ok = -1;
			scanf("%d%d", &x, &y);
			for (int j = 0; j < n; j++) {
				if (leftOfStick(xx[j], yy[j], x, y)) {
					++cnt[k];
					ok = 1;
					break;
				} else {
					++k;
				}
			}
			if (ok == -1)
				++cnt[k];
		}
		for (int i = 0; i <= n; i++) {
			printf("%d: %d\n", i, cnt[i]);
		}
	}
	return 0;
}
