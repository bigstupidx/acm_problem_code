#include <cstdio>
#include <cstring>

using namespace std;

void output(int a, int b) {
	if (a < 0 || b < 0 || a == b) {
		puts("impossible");
	} else if (a > b) {
		printf("%d %d\n", a, b);
	} else {
		printf("%d %d\n", b, a);
	}
	return;
}

int main() {
	int nca;
	scanf("%d", &nca);
	for (int i = 0; i < nca; ++i) {
		int x, y, a, b;
		scanf("%d%d", &x, &y);
		a = (x + y) / 2, b = (x - y) / 2;
		if (a >= 0 && b >= 0) {
			output(a, b);
		} else {
			b = (x + y) / 2, a = (x - y) / 2;
			output(a, b);
		}
	}
	return 0;
}
