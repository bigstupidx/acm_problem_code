#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long llong;

int p, q, d, pos, len, ans, cas;

int gcd(int a, int b) {
	int r;
	while (b) r = a % b, a = b, b = r;
	return a;
}

int pow_mod(int a, int n, int mod) {
	llong pow = 1;
	while (n) {
		if (n & 1) pow = pow * a % mod;
		n >>= 1;
		a = llong(a) * a % mod;
	}
	return pow;
}

int Euler_phi(int n) {
	int phi = n;
	for (llong i = 2; i * i <= n; ++i) {
		if (!(n % i)) {
			phi -= phi / i;
			while (!(n % i)) n /= i;
		}
	}
	if (n > 1) phi -= phi / n;
	return phi;
}

int main() {
	while (scanf("%d/%d", &p, &q) != EOF) {
		d = gcd(p, q);
		p /= d; q /= d;
		for (pos = 1; !(q & 1); q >>= 1) ++pos;
		ans = len = Euler_phi(q);
		for (int i = 1, t = sqrt(len * 1.0); i <= t; ++i) {
			if (!(len % i)) {
				if (pow_mod(2, i, q) == 1) ans = min(ans, i);
				if (pow_mod(2, len / i, q) == 1) ans = min(ans, len / i);
			}
		}
		printf("Case #%d: %d,%d\n", ++cas, pos, ans);
	}
	return 0;
}