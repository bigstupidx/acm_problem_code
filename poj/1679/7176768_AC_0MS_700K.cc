#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge {
	int x, y, d;

	bool operator<(const edge & a)const {
		return a.d > d;
	}
} e[10010];

int n, m, visit[10010], par[102];

int my_find(int x) {
	if (par[x] == -1) {
		return x;
	}
	return par[x] = my_find(par[x]);
}

bool kruskral(int &sum) {
	sum = 0;
	int cnt = 1;
	memset(par, -1, sizeof (par));
	for (int i = 0; i < m; i++) {
		if (visit[i])continue;
		int ii = my_find(e[i].x);
		int jj = my_find(e[i].y);
		if (ii != jj) {
			par[ii] = jj;
			sum += e[i].d;
			visit[i] = 1;
			if (++cnt == n)break;
		}
	}
	return cnt == n;
}

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].d);
		}
		sort(e, e + m);
		int sum = 0, tem;
		memset(visit, 0, sizeof (visit));
		if (kruskral(sum)) {
			int flag = 0;
			queue <int> Q;
			for (int i = 0; i < m; i++) {
				if (visit[i]) {
					Q.push(i);
				}
			}
			while (!Q.empty()) {
				int i = Q.front();
				Q.pop();
				memset(visit, 0, sizeof (visit));
				visit[i] = 1;
				if (kruskral(tem) && tem == sum) {
					flag = 1;
					break;
				}
			}
			if (flag)puts("Not Unique!");
			else {
				printf("%d\n", sum);
			}
		}
		else {
			printf("%d\n", sum);
		}
	}
	return 0;
}