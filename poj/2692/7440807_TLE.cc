#include <cstdio>
#include <cstring>

char str[22][90], ch;

struct node {
	int arr[22];
} nod[1002];

int n, m, cnt[22], flag[22], mark[1002];

void solve() {
	while (1) {
		int mm = 0;
		memset(cnt, 0, sizeof (cnt));
		for (int i = 0; i < m; i++) {
			if (mark[i])continue;
			int xflag = 0;
			for (int j = 0; j < n; j++) {
				if (!flag[nod[i].arr[j]]) {
					xflag = 1;
					cnt[nod[i].arr[j]]++;
					mm++;
					break;
				}
			}
			if (!xflag)mark[i] = 1;
		}
		if (mm == 0)break;
		int mini = 1000000, maxi = -1;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] > mm / 2) {
				printf("%s\n", str[i]);
				return;
			}
			if (cnt[i] > maxi)maxi = cnt[i];
			if (cnt[i] < mini)mini = cnt[i];
		}
		if (mini == maxi)break;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] == mini) {
				flag[i] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			printf("%s\n", str[i]);
		}
	}
}

int main() {
	scanf("%d", &n);
	while ((ch = getchar()) != '\n');
	for (int i = 1; i <= n; i++) {
		gets(str[i]);
	}
	while (scanf("%d", &nod[m].arr[0]) != EOF) {
		for (int i = 1; i < n; i++) {
			scanf("%d", &nod[m].arr[i]);
		}
		m++;
	}
	solve();
	return 0;
}
