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
		for (int j = 0; j < n; j++) {
			dis[i][j] = inf;
		}
		dis[i][i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (nod[i].id != nod[j].id) {
				tem = Distance(i, j);
				tem = tem * 6 / 1000;
				dis[i][j] = tem;
				dis[j][i] = tem;
			}
		}
	}
	for (int i = 2; i < n; i++) {
		if (nod[i].id == nod[i - 1].id) {
			tem = Distance(i, i - 1);
			tem = tem * 3 / 2000;
			dis[i][i - 1] = tem;
			dis[i - 1][i] = tem;
		}
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
	int x, y, id = 2, n = 1;
	scanf("%d%d", &nod[0].x, &nod[0].y);
	scanf("%d%d", &nod[1].x, &nod[1].y);
	nod[1].id = 1;
	while (scanf("%d%d", &x, &y) != EOF) {
		nod[++n].x = x, nod[n].y = y, nod[n].id = id;
		while (scanf("%d%d", &x, &y) != EOF) {
			if (x == -1 && y == -1)break;
			nod[++n].x = x, nod[n].y = y, nod[n].id = id;
		}
		id++;
	}
	n++;
	solve(n);
	return 0;
}
