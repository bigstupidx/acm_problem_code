#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int n, m, a[1002], b[1002];

struct Qnode {
	double d;
	int ii;

	bool operator<(const Qnode & a)const {
		return a.d > d;
	}
} now;

double solve(double g) {
	priority_queue <Qnode> Q;
	for (int i = 0; i < n; i++) {
		now.d = a[i] - g * b[i];
		now.ii = i;
		Q.push(now);
	}
	int k = n - m;
	long long lf = 0, rt = 0;
	while (k--) {
		now = Q.top();
		Q.pop();
		lf += a[now.ii];
		rt += b[now.ii];
	}
	return lf * 1.0 / rt;
}

int main() {
	while (scanf("%d%d", &n, &m), n || m) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
		}
		double now = 0, next = -1;
		while (fabs(now - next) > 1e-8) {
			//printf("%.2lf %.2lf\n", now, next);
			next = now;
			now = solve(now);
		}
		printf("%.0lf\n", now * 100);
	}
	return 0;
}
