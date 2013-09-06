#include <cstdio>
#include <cmath>
#include <cstring>

struct node {
	int r, g, b;
} nod[20];

double Distance(int i, int j) {
	double ax = nod[i].r - nod[j].r;
	double by = nod[i].g - nod[j].g;
	double cz = nod[i].b - nod[j].b;
	return sqrt(ax * ax + by * by + cz * cz);
}

int main() {
	for (int i = 0; i < 16; i++) {
		scanf("%d%d%d", &nod[i].r, &nod[i].g, &nod[i].b);
	}
	while (1) {
		scanf("%d%d%d", &nod[16].r, &nod[16].g, &nod[16].b);
		if (nod[16].r == -1 && nod[16].g == -1 && nod[16].b == -1)break;
		int ii = 0;
		double dis, tem;
		dis = Distance(0, 16);
		for (int i = 1; i < 16; i++) {
			tem = Distance(i, 16);
			if (tem < dis) {
				ii = i;
				dis = tem;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", nod[16].r, nod[16].g, nod[16].b, nod[ii].r, nod[ii].g, nod[ii].b);
	}
	return 0;
}
