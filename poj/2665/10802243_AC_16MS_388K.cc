#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m), n || m) {
		for (int x, y, i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			if (x > y) {
				int temp = x;
				x = y;
				y = temp;
			}
			n -= (y - x) + 1;
		}
		printf("%d\n", n + 1);
	}
	return 0;
}
