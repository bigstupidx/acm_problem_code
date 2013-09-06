
#include <cstdio>
#include <cstring>

using namespace std;

int n, arr[5002], c[5002], f[5002];

void solve() {
	memset(f, 0, sizeof (f));
	memset(c, 0, sizeof (c));
	c[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = i - 1, tp = -1; j >= 0; j--) {
			if (arr[j] > arr[i]) {
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
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		if (f[i] > maxi)maxi = f[i];
	}
	printf("%d %d\n", maxi, c[n]);
}

int main() {
	arr[0] = 1 << 30;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", arr + i);
		}
		arr[++n] = 0;
		solve();
	}
	return 0;
}
/*
#include <iostream>
#include <limits.h>
using namespace std;
#define inf INT_MAX;
int data[5003];
int dp[5003];
int c[5003];
int minNow = 0;

void lds(int n) {
	memset(dp, 0, sizeof (dp));
	minNow = 0;
	memset(c, 0, sizeof (c));
	c[0] = 1;
	int t;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		t = -1;
		for (int j = i - 1; j >= 0; j--) {
			if (data[i] < data[j]) {
				if (dp[j] + 1 == dp[i] && data[j] != t) {//所以不会出现count加了不应该加的东西,exp:6 7 6 7 6 4
					c[i] += c[j];
					t = data[j]; //同理，不可能出现data【j】之前相同的元素，所以直接可以赋值给下一个

				}
				else if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					c[i] = c[j];
					t = data[j];
				}
			}
		}
	}
	int out = 0;
	for (int i = 0; i < n; i++)
		out = max(out, dp[i]);
	cout << out << " ";
	cout << c[n] << endl;

};

int main() {
	int n;
	cin >> n;
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &data[i]);
		data[0] = 1 << 30;
		lds(n + 1);

	}
}
 */