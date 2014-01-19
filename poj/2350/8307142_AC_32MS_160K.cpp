#include <cstdio>
#include <cstring>

using namespace std;

int n;
double arr[1002];

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		scanf("%d", &n);
		double sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf", &arr[i]);
			sum += arr[i];
		}
		double average = sum * 1.0 / n;
		for (int i = 0; i < n; i++) {
			if (arr[i] > average) {
				++cnt;
			}
		}
		printf("%.3lf%%\n", (100.0 * cnt) / n);
	}
	return 0;
}
