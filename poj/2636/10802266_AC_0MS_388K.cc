#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		int n, ans = 1, sum = 0;
		scanf("%d", &n);
		for (int value, i = 0; i < n; i++) {
			scanf("%d", &value);
			sum += value - 1;
		}
		++sum;
		printf("%d\n", ans > sum ? ans : sum);
	}
	return 0;
}
