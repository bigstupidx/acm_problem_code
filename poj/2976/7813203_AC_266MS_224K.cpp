#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n, m, a[1002], b[1002];

bool solve(double g) {
	priority_queue <double> Q;
	double temp, sum = 0;
	for (int i = 0; i < n; i++) {
		temp = a[i] - g * b[i];
		Q.push(temp);
	}
	int k = n - m;
	while (k--) {
		sum += Q.top();
		Q.pop();
	}
	//printf("%.2lf %.2lf\n", g, sum);
	return sum < 0;
}

int main() {
	while (scanf("%d%d", &n, &m), n || m) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
		}
		double lf = 0, rt = 2, mid;
		while (rt - lf > 1e-8) {
			mid = (rt + lf) / 2;
			if (solve(mid)) {
				rt = mid;
			}
			else {
				lf = mid;
			}
		}
		printf("%.0lf\n", lf * 100);
	}
	return 0;
}
