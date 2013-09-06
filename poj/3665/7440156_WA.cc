#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct Qnode {
	int v, id;

	bool operator<(const Qnode & a)const {
		if (a.v == v)return a.id < id;
		return a.v > v;
	}
} now;

int main() {
	//freopen("in.txt", "r", stdin);
	int n, k;
	priority_queue <Qnode> Q[2];
	scanf("%d%d", &n, &k);
	for (int x, i = 0; i < n; i++) {
		scanf("%d", &x);
		now.v = x;
		now.id = i;
		Q[0].push(now);
	}
	int ii = 0;
	for (int i = 0; i < k; i++, ii = (ii + 1) % 2) {
		now = Q[ii].top();
		Q[ii].pop();
		printf("%d\n", now.id + 1);
		if (n != 1) {
			int x = now.v / (n - 1);
			int y = now.v % (n - 1);
			now.v = 0;
			Q[(ii + 1) % 2].push(now);
			while (!Q[ii].empty()) {
				now = Q[ii].top();
				Q[ii].pop();
				now.v += x;
				if (y) {
					now.v++;
					y--;
				}
				Q[(ii + 1) % 2].push(now);
			}
		}
	}
	return 0;
}