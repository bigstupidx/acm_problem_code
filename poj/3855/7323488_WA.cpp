#include <cstdio>
#include <cstring>

struct point {
	double x, y;
} pp[102];

double cross1(point &a, point &b, point &c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void PolygonGravity(point p[], int n, point &G) {
	G.x = G.y = 0;
	double tot = 0, s = 0;
	for (int i = 1; i < n - 1; i++, tot += s) {
		s = cross1(p[0], p[i], p[i + 1]);
		G.x += s * (p[0].x + p[i].x + p[i + 1].x);
		G.y += s * (p[0].y + p[i].y + p[i + 1].y);
	}
	G.x /= tot * 3;
	G.y /= tot * 3;
}

int main(){
	int n;
	while(scanf("%d", &n), n){
		point tem;
		for(int i=0;i<n;i++){
			scanf("%lf%lf", &pp[i].x, &pp[i].y);
		}
		PolygonGravity(pp, n, tem);
		printf("%lf %lf\n", tem.x, tem.y);
	}
	return 0;
}