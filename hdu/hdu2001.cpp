#include <cstdio>
#include <cmath>

int main() {
	int x1, y1, x2, y2;
	while (scanf("%d%d%d%d", &x1, &y1, &x2, &y2) != EOF) {
		double xx = x1 - x2;
		double yy = y1 - y2;
		printf("%.2lf\n", sqrt(xx * xx + yy * yy));
	}
	return 0;
}
