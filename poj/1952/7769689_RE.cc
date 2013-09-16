#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

int n, f[5002], c[5002], arr[5002];
bool flag[5002];

void solve() {
	f[0] = 1;
	for (int i = 1; i < n; i++) {
		f[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				if (f[i] < f[j] + 1) {
					f[i] = f[j] + 1;
				}
			}
		}
	}
	int mini = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		if (mini < f[i]) {
			mini = f[i];
		}
	}
	for (int i = 0; i < n; i++) {
		c[i] = 1;
		memset(flag, 0, sizeof (flag));
		for (int j = 0, xflag = 0; j < i; j++) {
			if (arr[j] > arr[i] && f[i] == f[j] + 1) {
				if (flag[arr[j]])continue;
				flag[arr[j]] = true;
				if (xflag) c[i] += c[j];
				else xflag = 1, c[i] = c[j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (mini == f[i]) {
			sum += c[i];
		}
	}
	printf("%d %d\n", mini, sum);
}

int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		solve();
	}
	return 0;
}
