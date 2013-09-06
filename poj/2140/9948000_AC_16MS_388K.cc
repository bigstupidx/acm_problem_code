#include <cstdio>
#include <cstring>

using namespace std;

int n;

int solve() {
	int k = 0, ans = 0;
	bool flag = true;
	while (k < n && flag) {
		int m = 2 * n;
		if (m % (k + 1) == 0) {
			int ax = m / (k + 1) - k;
			if (ax <= 0)
				break;
			if (ax % 2 == 0) {
				++ans;
			}
		}
		++k;
	}
	return ans;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", solve());
	}
	return 0;
}
