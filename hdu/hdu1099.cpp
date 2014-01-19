#include <cstdio>
#include <cstring>

#define __int64 long long

using namespace std;

void solve(__int64 &a, __int64 &b, int c, int d) {
	__int64 aa = a * d + b * c;
	__int64 bb = b * d;
	a = aa;
	b = bb;
}

__int64 gcd(__int64 a, __int64 b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int getLength(__int64 x) {
	int j = 0;
	while (x != 0) {
		++j;
		x /= 10;
	}
	return j;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		__int64 a = 1, b = 1, c;
		for (int i = 1; i < n; i++) {
			solve(a, b, n, n - i);
			c = gcd(a, b);
			a /= c;
			b /= c;
		}
//		printf("%lld %lld\n", a, b);
		__int64 aa = a / b;
		__int64 bb = a % b;
		if (bb == 0) {
			printf("%lld\n", aa);
		} else {
			int len_aa = getLength(aa) + 1;
			int len_bb = getLength(b);
			for (int i = 0; i < len_aa; i++)
				putchar(' ');
			printf("%lld\n", bb);
			printf("%lld ", aa);
			for (int i = 0; i < len_bb; i++)
				putchar('-');
			puts("");
			for (int i = 0; i < len_aa; i++)
				putchar(' ');
			printf("%lld\n", b);
		}
	}
	return 0;
}
