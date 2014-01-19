#include <cstdio>
#include <cstring>

using namespace std;

void solve() {
	int x, y;
	scanf("%d%d", &x, &y);
	if (x == y) {
		if (x % 2 == 0) {
			printf("%d\n", 2 * x);
		} else {
			printf("%d\n", 2 * (x - 1) + 1);
		}
	} else if (x == y + 2) {
		if (x % 2 == 0) {
			printf("%d\n", 2 * x - 2);
		} else {
			printf("%d\n", 2 * x - 3);
		}
	} else {
		puts("No Number");
	}
	return;
}

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		solve();
	}
	return 0;
}
