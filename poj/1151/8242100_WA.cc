#include <cstdio>
#include <cstring>

using namespace std;

struct node {
	double a, b, c, d;
} nod[102];

int n;

bool judge(int i, int j) {
	if (nod[i].a < nod[j].c && nod[i].c > nod[j].a) {
		if (nod[i].b < nod[j].d && nod[i].d > nod[j].b) {
			return true;
		}
		return false;
	}
	return false;
}

double cal(double a, double b, double c, double d) {
	return (b > d ? d : b) - (a > c ? a : c);
}

int main() {
	int nca = 0;
	while (scanf("%d", &n), n) {
		double sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf%lf%lf", &nod[i].a, &nod[i].b, &nod[i].c, &nod[i].d);
			sum += (nod[i].c - nod[i].a) * (nod[i].d - nod[i].b);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (judge(i, j)) {
					double ax = cal(nod[i].a, nod[i].c, nod[j].a, nod[j].c);
					double by = cal(nod[i].b, nod[i].d, nod[j].b, nod[j].d);
					sum -= ax * by;
				}
			}
		}
		printf("Test case #%d\n", ++nca);
		printf("Total explored area: %.2lf\n\n", sum);
	}
	return 0;
}
