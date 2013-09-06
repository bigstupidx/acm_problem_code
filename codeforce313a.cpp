#include <cstdio>
#include <cstring>

using namespace std;

void solve(int n) {
	if (n >= 0)
		printf("%d\n", n);
	else {
		n = -n;
		if (n < 10) {
			printf("%d\n", 0);
		} else {
			int x1 = n / 10;
			int x2 = (n / 100) * 10 + n % 10;

			printf("%d\n", -(x1 < x2 ? x1 : x2));
		}
	}
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		solve(n);
	}
	return 0;
}
