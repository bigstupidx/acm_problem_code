#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, x1, x2, y1, y2, cnt[1002];

struct node {
	int x1, x2;
	bool operator <(const node &a) const {
		if (a.x1 < x1 && a.x1 < x2) {
			return false;
		}
		if (a.x2 < x1 && a.x2 < x2) {
			return false;
		}
		return true;
	}
} nod[1002];

bool leftOfBox(int x, int y, int i) {
	int ax = nod[i].x1 - nod[i].x2;
	int ay = y1 - y2;

	int bx = x - nod[i].x2;
	int by = y - y2;

	if (ax * by - ay * bx < 0) {
		return false;
	}
	return true;
}

int main() {
	while (scanf("%d", &n), n) {
		scanf("%d%d%d%d%d", &m, &x1, &y1, &x2, &y2);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &nod[i].x1, &nod[i].x2);
		}
		memset(cnt, 0, sizeof(cnt));
		sort(nod, nod + n);
//		for(int i = 0;i<n;i++){
//			printf("%d ", nod[i].x1);
//		}
//		puts("");
		for (int i = 0; i < m; i++) {
			int x, y, flag = -1;
			scanf("%d%d", &x, &y);
			for (int j = 0; j < n; j++) {
				if (leftOfBox(x, y, j)) {
					++cnt[j];
					flag = 1;
					break;
				}
			}
			if (flag == -1) {
				++cnt[n];
			}
		}
//		for (int i = 0; i <= n; i++) {
//			printf("%d ", cnt[i]);
//		}
//		puts("");
		map<int, int> mp;
		map<int, int>::iterator p;
		for (int i = 0; i <= n; i++) {
			if (cnt[i] > 0) {
				p = mp.find(cnt[i]);
				if (p == mp.end()) {
					mp[cnt[i]] = 1;
				} else {
					++p->second;
				}
			}
		}
		puts("Box");
		for (p = mp.begin(); p != mp.end(); p++) {
			printf("%d: %d\n", p->first, p->second);
		}
	}
	return 0;
}
