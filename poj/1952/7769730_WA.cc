#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

int n, f[5002], c[5002], arr[5002];
bool flag[70002];

void solve() {
	f[0] = 1, c[0] = 1;
	for (int i = 1; i < n; i++) {
		f[i] = 1, c[i] = 1;
		for (int j = 0, tp = -1; j < i; j++) {
			if (arr[i] < arr[j]) {
				if (f[i] < f[j] + 1) {
					f[i] = f[j] + 1;
					c[i] = c[j];
					tp = arr[j];
				}
				else if (f[i] == f[j] + 1 && tp != arr[j]) {
					c[i] += c[j];
					tp = arr[j];
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
