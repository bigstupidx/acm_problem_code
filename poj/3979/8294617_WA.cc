#include <cstdio>
#include <cstring>

using namespace std;

char str[10];

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void output(int a, int b) {
	if (a == 0) {
		puts("0");
		return;
	}
	if (a < 0) {
		printf("-");
		a = -a;
	}
	int c = gcd(a, b);
	printf("%d/%d\n", a / c, b / c);
}

void solve() {
	int a = str[0] - '0';
	int b = str[2] - '0';
	int c = str[4] - '0';
	int d = str[6] - '0';
	if (str[3] == '-') {
		a = a * d - c * b;
	} else {
		a = a * d + c * b;
	}
	output(a, b * d);
}

int main() {
	while (scanf("%s", str) != EOF) {
		solve();
	}
	return 0;
}
