#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

struct node {
	int x, y, id;
} nod[222];
double dis[222][222], inf = 1e100;

double Distance(int i, int j) {
	double ax = nod[i].x - nod[j].x;
	double by = nod[i].y - nod[j].y;
	return sqrt(ax * ax + by * by);
}

void solve(int n) {
	double tem;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			tem = Distance(i, j);
			if (nod[i].id == nod[j].id) {
				tem = tem * 3 / 2000;
				dis[i][j] = dis[j][i] = tem;
			}
			else {
				tem = tem * 6 / 1000;
				dis[i][j] = dis[j][i] = tem;
			}
		}
		dis[i][i] = 0;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	printf("%d\n", (int) (dis[0][1] + 0.5));
}

int main() {
	//freopen("in.txt", "r", stdin);
	int x, y, id = 2, n = 2;
	scanf("%d%d", &nod[0].x, &nod[0].y);
	scanf("%d%d", &nod[1].x, &nod[1].y);
	nod[1].id = 1;
	while (scanf("%d%d", &x, &y) != EOF) {
		if (x == -1 && y == -1)continue;
		nod[n].x = x, nod[n].y = y, nod[n].id = id;
		n++;
		while (scanf("%d%d", &x, &y) != EOF) {
			if (x == -1 && y == -1)break;
			nod[n].x = x, nod[n].y = y, nod[n].id = id;
			n++;
		}
		id++;
	}
	solve(n);
	return 0;
}
