#include <cstdio>
#include <cstring>

int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int a, b, c, d;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
		if (a * d > b * c) {
			int xx = a * d - b * c;
			int yy = a * d;
			int zz = gcd(xx, yy);
			printf("%d/%d\n", xx / zz, yy / zz);
		} else {
			int xx = b * c - a * d;
			int yy = b * c;
			int zz = gcd(xx, yy);
			printf("%d/%d\n", xx / zz, yy / zz);
		}
	}
	return 0;
}
