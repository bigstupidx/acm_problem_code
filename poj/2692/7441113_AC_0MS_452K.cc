#include <cstdio>
#include <cstring>

struct node {
	int start;
	int arr[21];
} nod[1002];

int n, m, cnt[22], mark[1002], flag[22];

char name[21][82], ch;

void solve() {
	while (1) {
		int mm = 0;
		memset(cnt, 0, sizeof (cnt));
		for (int i = 0; i < m; i++) {
			if (mark[i])continue;
			int xflag = 0;
			for (int j = nod[i].start; j < n; j++) {
				if (!flag[nod[i].arr[j]]) {
					nod[i].start = j;
					cnt[nod[i].arr[j]]++;
					mm++;
					xflag = 1;
					break;
				}
			}
			if (!xflag)mark[i] = 1;
		}
		if (!mm)return;
		int mini = 10000000, maxi = -1;
		for (int i = 1; i <= n; i++) {
			if (flag[i])continue;
			if (cnt[i] > mm / 2) {
				printf("%s\n", name[i]);
				return;
			}
			if (cnt[i] > maxi)maxi = cnt[i];
			if (cnt[i] < mini)mini = cnt[i];
		}
		if (mini == maxi) {
			for (int i = 1; i <= n; i++) {
				if (cnt[i] == mini)printf("%s\n", name[i]);
			}
			return;
		}
		for (int i = 1; i <= n; i++) {
			if (cnt[i] == mini)flag[i] = 1;
		}
	}
}

int main() {
	scanf("%d", &n);
	while ((ch = getchar()) != '\n');
	for (int i = 1; i <= n; i++) {
		gets(name[i]);
	}
	while (scanf("%d", &nod[m].arr[0]) != EOF) {
		for (int j = 1; j < n; j++) {
			scanf("%d", &nod[m].arr[j]);
		}
		m++;
	}
	solve();
	return 0;
}
