#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;
const double EPS = 1e-10;

struct point {
	double x, y;
}p[MAX_N], ch[MAX_N];


bool Verticalcmp(const point &a, const point &b) {
	return a.y + EPS < b.y || (a.y < b.y + EPS && a.x < b.x);
}

int sign(double x) {
	if (x > EPS) return 1;
	else if (x < -EPS) return -1;
	else return 0;
}

bool PointEqual(point &a, point &b) {
	return !sign(a.x - b.x) && !sign(a.y - b.y);
}

double cross1(point &a, point &b, point &c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void GrahamScan1(point p[], int n, point ch[], int &m) {
	m = 0;
	sort(p, p + n, Verticalcmp); n = unique(p, p + n, PointEqual) - p;
	for (int i = 0; i < n; i++) {
		while (m > 1 && sign(cross1(ch[m - 2], ch[m - 1], p[i])) <= 0) m--;
		ch[m++] = p[i];
	}
	int t = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m > t && sign(cross1(ch[m - 2], ch[m - 1], p[i])) <= 0) m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
}

char buf[10000];

int main() {
	while (1) {
		double x, y;
		int t;
		int n = 0, m;
		while (1) {
			while ((t = getchar()) != '(' && t != '\n' && t != EOF) ;
			if (t == EOF || t == '\n') break;
			scanf("%lf,%lf", &x, &y);
			p[n].x = x; p[n++].y = y;
		}
		GrahamScan1(p, n, ch, m);
		for (int i = 0; i < m; ++i) {
			printf("(%f,%f) ", ch[i].x, ch[i].y);
		}
		if (m > 1) printf("(%f,%f)\n", ch[0].x, ch[0].y);
		if (t == EOF) break;
	}
	return 0;
}




