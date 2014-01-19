/**
 * 求n！的位数
 * */

#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
	int nca, n;
	scanf("%d", &nca);
	while (nca--) {
		scanf("%d", &n);
		double ans = 1;
		for (int i = 1; i <= n; i++) {
			ans += log10(i);
		}
		printf("%d\n", (int) ans);
	}
	return 0;
}
