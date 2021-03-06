#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

int n, f[5002], c[5002], arr[5002];

void solve() {
	c[0] = 1, f[0] = 1;
	for (int i = 1; i < n; i++) {
		c[i] = 1, f[i] = 1;
		set <int> st;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				if (f[i] < f[j] + 1) {
					f[i] = f[j] + 1;
					c[i] = c[j];
					st.clear();
					st.insert(arr[j]);
				}
				else if (f[i] == f[j] + 1) {
					if (st.find(arr[j]) != st.end())continue;
					st.insert(arr[j]);
					c[i] += c[j];
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
