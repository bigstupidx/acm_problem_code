#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

char str[30];
int n, s, t, tim, ppl[12], dis[12][12], last[12];

struct QN {
	int u;
	int c;
	int f;
	int cur;
	int ser;

	bool operator<(const QN & a)const {
		if (a.cur == cur)
			return a.ser > ser;
		return a.cur<cur;
	}
};

int get_next(int u) {
	if (last[u] == -1)
		return (u + 1) % n;
	if ((last[u] + 1) % n == u)
		return (last[u] + 2) % n;
	return (last[u] + 1) % n;
}

int main() {
	while (scanf("%s", str), strcmp(str, "TheEnd") != 0) {
		scanf("%d%d%d", &n, &s, &t);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)dis[i][j] = 0;
				else
					scanf("%d", &dis[i][j]);
			}
		}
		int sum = 0;
		for (int i = 1; i < n; i++) {
			scanf("%d", &ppl[i]);
			sum += ppl[i];
		}
		scanf("%d", &tim);

		QN now, nnew;
		priority_queue<QN>Q;
		memset(last, -1, sizeof (last));

		now.u = 0;
		now.c = -1;
		now.cur = 0;
		now.ser = 0;
		Q.push(now);

		int x = 0, k = 0, iPreTime = -1;
		bool newCar = false;
		while (!Q.empty()) {
			now = Q.top();
			Q.pop();
			int u = now.u;
			int cur = now.cur;
			if (cur > tim)break;
			if (iPreTime != cur)
				newCar = false;
			if (u == 0) {
				if (now.c == -1) {
					now.c = s - k*t;
					if (now.c < 3)
						now.c = 3;
					k++;
				} else {
					x += now.f;
					if (x == sum)break;
				}
				now.f = 0;
				now.u = get_next(0);
				now.cur += dis[0][now.u];
				now.ser += dis[0][now.u];
				Q.push(now);
				last[0] = now.u;
			} else {
				if (now.f + ppl[u] > now.c) {
					ppl[u] -= now.c - now.f;
					now.f = now.c;
					if (!newCar) {
						newCar = true;
						nnew.u = 0;
						nnew.c = -1;
						nnew.cur = cur + 2;
						nnew.ser = 0;
						Q.push(nnew);
					}
					now.u = 0;
					now.cur += dis[u][0];
					now.ser += dis[u][0];
					Q.push(now);
					last[u] = 0;
				} else {
					now.f += ppl[u];
					ppl[u] = 0;
					if (now.f == now.c)
						now.u = 0;
					else
						now.u = get_next(u);
					now.cur += dis[u][now.u];
					now.ser += dis[u][now.u];
					Q.push(now);
					last[u] = now.u;
				}
			}
		}
		puts(str);
		if (x == sum)
			printf("%d seconds needed\n", now.cur);
		else
			printf("%d contestants reached\n", x);
	}
	return 0;
}