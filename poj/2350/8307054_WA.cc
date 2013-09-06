#include <cstdio>
#include <cstring>

using namespace std;

int n, arr[1002];

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		scanf("%d", &n);
		int sum = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		double average = sum * 1.0 / n;
		for (int i = 0; i < n; i++) {
			if (arr[i] > average) {
				++cnt;
			}
		}
		printf("%.3lf\n", cnt * 1.0 / n);
	}
	return 0;
}
