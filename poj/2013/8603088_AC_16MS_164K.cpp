#include <cstdio>
#include <cstring>

using namespace std;

char str[20][30];

void solve(int n, int nca) {
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	printf("SET %d\n", nca);
	for (int i = 0; i < n; i += 2) {
		printf("%s\n", str[i]);
	}
	if (n % 2 == 0) {
		--n;
	} else {
		n -= 2;
	}
	for (int i = n; i >= 0; i -= 2) {
		printf("%s\n", str[i]);
	}
	return;
}

int main() {
	int n, nca = 0;
	while (scanf("%d", &n), n) {
		solve(n, ++nca);
	}
	return 0;
}
