#include <cstdio>
#include <cstring>
#include <cmath>

const int MAX_N = 1000001;
const int MAX_SQR = 46000;
const int MAX_PRIMES = 1000000;

struct complex {
	int a, b;
}cp[MAX_PRIMES];

int prime[MAX_PRIMES];
bool isPrime[MAX_N];
unsigned sqr[MAX_SQR];

int CalcPrime(int prime[], bool isPrime[], int n) {
	memset(isPrime, 1, sizeof(isPrime[0]) * (n + 1));
	isPrime[0] = isPrime[1] = 0;
	int m = 0;
	for (int i = 2; i <= n; ++i) {
		if (isPrime[i]) {
			prime[m++] = i;
		}
		for (int j = 0; i * prime[j] <= n; ++j) {
			isPrime[i * prime[j]] = 0;
			if (!(i % prime[j])) break;
		}
	}
	return m;
}

int main() {
	int m = CalcPrime(prime, isPrime, MAX_N - 1);
	memset(isPrime, 0, sizeof(isPrime));
	for (int i = 0; i < MAX_SQR; ++i) {
		sqr[i] = i * i;
		if (sqr[i] < MAX_N) isPrime[sqr[i]] = 1;
	}
	for (int i = 0; i < m; ++i) {
		if (prime[i] % 4 == 3) {
			cp[i].a = cp[i].b = -1;
			continue;
		}
		for (int j = 0; j < MAX_SQR; ++j) {
			if (prime[i] < sqr[j] * 2) break;
			if (isPrime[prime[i] - sqr[j]]) {
				cp[i].a = j;
				cp[i].b = int(sqrt(1.0 * prime[i] - sqr[j]));
				break;
			}
		}
	}
	int n;
	int cas = 1;
	while (scanf("%d", &n) != EOF) {
		printf("Case #%d:", cas++);
		bool first = 1;
		for (int i = 0; i < m && n >= prime[i]; ++i) {
			if (!(n % prime[i])) {
				while (!(n % prime[i])) n /= prime[i];
				if (first) first = 0;
				else putchar(',');
				if (cp[i].a >= 0) {
					if (cp[i].b == 1) {
						printf(" %d+j, %d-j", cp[i].a, cp[i].a);
					} else {
						printf(" %d+%dj, %d-%dj", cp[i].a, cp[i].b, cp[i].a, cp[i].b);
					}
				} else {
					printf(" %d", prime[i]);
				}
			}
		}
		if (n > 1) {
			if (n % 4 == 3) {
				printf(" %d", n);
			} else {
				for (int i = 0; i < MAX_SQR; ++i) {
					if (n < sqr[i] * 2) break;
					int t = n - sqr[i];
					t = int(sqrt(1.0 * t));
					if (t * t == n - sqr[i]) {
						if (t == 1) {
							printf(" %d+j, %d-j", i, i);
						} else {
							printf(" %d+%dj, %d-%dj", i, t, i, t);
						}
					}
				}
			}
		}
		puts("");
	}
	return 0;
}