#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, cnt[20];

int main() {
	while (scanf("%d", &n) != EOF) {
		memset(cnt, 0, sizeof(cnt));

		for (int index, i = 0; i < n; i++) {
			scanf("%d", &index);
			++cnt[index];
		}
		n /= 3;
		if (cnt[5] != 0 || cnt[7] != 0 || cnt[1] != n || cnt[2]<cnt[4] || cnt[4] + cnt[6] != n || cnt[2] - cnt[4] + cnt[3] != cnt[6]) {
			puts("-1");
		} else {
			for (int i = 0; i < cnt[4]; i++) {
				puts("1 2 4");
			}
			for (int i = 0, m = cnt[2] - cnt[4]; i < m; i++) {
				puts("1 2 6");
			}
			for (int i = 0; i < cnt[3]; i++) {
				puts("1 3 6");
			}
		}
	}
	return 0;
}
