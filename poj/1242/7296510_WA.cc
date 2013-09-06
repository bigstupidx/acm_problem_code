#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

struct node {
	int x, y;
} nod[10010];

int n, m, tem[102][102], g[102][102];

inline int ABS(int x) {
	return x > 0 ? x : -x;
}

void roll() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tem[i][j] = g[j][n - i - 1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = tem[i][j];
		}
	}
}

void front_back() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tem[i][j] = g[i][n - j - 1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = tem[i][j];
		}
	}
}

double solve() {
	double ans = 1e100, xx;

	map <int, int> mp;
	map <int, int> ::iterator p;

	for (int i = 0; i < m; i++) {
		mp.insert(make_pair(nod[i].y, nod[i].x - 1));
	}

	for (int k = 1, i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = k++;
		}
	}

	for (int ii = 0; ii < 4; ii++) {
		int sum = 0, tp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				p = mp.find(g[i][j]);
				if (p != mp.end()) {
					tp = p->second;
					sum += ABS(tp / n - i) + ABS(tp % n - j);
				}
			}
		}
		sum += m;
		printf("%d ", sum);
		xx = sum * 1.0 / m;
		if (xx < ans)ans = xx;
		front_back();
		sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				p = mp.find(g[i][j]);
				if (p != mp.end()) {
					tp = p->second;
					sum += ABS(tp / n - i) + ABS(tp % n - j);
				}
			}
		}
		sum += m;
		printf("%d\n", sum);
		xx = sum * 1.0 / m;
		if (xx < ans)ans = xx;
		front_back();
		roll();
	}
	return ans;
}

int main() {
	int nca = 1, flag = 0;
	while (scanf("%d", &n), n) {
		if (flag)puts("");
		else flag = 1;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &nod[i].x, &nod[i].y);
		}
		printf("Scenario %d: smallest average = %.4f\n", nca++, solve());
	}
	return 0;
}

