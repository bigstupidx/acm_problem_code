#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int LIMIT = 65537;
const int MAX_PRIMES = 7000;

struct Complex {
	int a, b;
	Complex() {}
	Complex(int a, int b) : a(a), b(b) {}
	bool operator <(const Complex &c) const {
		return a < c.a || a == c.a && b < c.b;
	}
};

int prime[MAX_PRIMES];
bool isPrime[LIMIT];
Complex cp[MAX_PRIMES];
int sqr[LIMIT];
int n, cas;
vector <Complex> ans;

int CalcPrime(int prime[], bool isPrime[], int n) {
	memset(isPrime, 1, sizeof(isPrime[0]) * (n + 1));
	isPrime[0] = isPrime[1] = 0;
	int m = 0;
	for (int i = 2; i <= n; ++i) {
		if (isPrime[i]) prime[m++] = i;
		for (int j = 0; i * prime[j] <= n; ++j) {
			isPrime[i * prime[j]] = 0;
			if (!(i % prime[j])) break;
		}
	}
	return m;
}

void CalcFactor(Complex cp[], int prime[], int n) {
	for (int i = 0; i < n; ++i) {
		if (prime[i] % 4 == 3) {
			cp[i].a = prime[i];
			cp[i].b = 0;
		} else {
			cp[i].a = prime[i]; cp[i].b = 0;
			for (int j = 1; sqr[j] * 2 <= prime[i]; ++j) {
				int t = int(sqrt(1.0 * (prime[i] - sqr[j])));
				if (t * t + sqr[j] == prime[i]) {
					cp[i].a = j;
					cp[i].b = t;
					break;
				}
			}
		}
	}
}

int main() {
	int m = CalcPrime(prime, isPrime, LIMIT - 1);
	for (int i = 1; i < LIMIT - 1; ++i) sqr[i] = i * i;
	CalcFactor(cp, prime, m);
	while (scanf("%d", &n) != EOF) {
		ans.clear();
		for (int i = 0; i < m && prime[i] <= n; ++i) {
			if (!(n % prime[i])) {
				while (!(n % prime[i])) n /= prime[i];
				ans.push_back(cp[i]);
			}
		}
		if (n > 1) {
			if (n % 4 == 3) {
				ans.push_back(Complex(n, 0));
			} else {
				for (int i = 1; sqr[i] * 2 <= n; ++i) {
					int t = int(sqrt(1.0 * (n - sqr[i])));
					if (t * t + sqr[i] == n) {
						ans.push_back(Complex(i, t));
						break;
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		printf("Case #%d:", ++cas);
		bool first = 1;
		for (int i = 0; i < ans.size(); ++i) {
			if (first) first = 0;
			else putchar(',');
			if (ans[i].b) {
				if (ans[i].b == 1) printf(" %d+j, %d-j", ans[i].a, ans[i].a);
				else printf(" %d+%dj, %d-%dj", ans[i].a, ans[i].b, ans[i].a, ans[i].b);
			} else {
				printf(" %d", ans[i].a);
			}
		}
		puts("");
	}
	return 0;
}
