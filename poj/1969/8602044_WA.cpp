#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int sum;
	while (scanf("%d", &sum) != EOF) {
		int n = 1, total = 0;
		for (n = 1;; ++n) {
			total += n;
			if (total >= sum)
				break;
		}
		total -= n;
		printf("%d %d \n", n, total);
		if (n % 2 == 0) {
			int x = n, y = 1;
			while (++total < sum) {
				--x;
				++y;
			}
			printf("TERM %d IS %d/%d\n", sum, x, y);
		} else {
			int x = 1, y = n;
			while (++total < sum) {
				++x;
				--y;
			}
			printf("TERM %d IS %d/%d\n", sum, x, y);
		}
	}
	return 0;
}
