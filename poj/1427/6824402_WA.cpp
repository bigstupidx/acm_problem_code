#include <cstdio>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

char ncase[30];
int n, s, t, dis[12][12], tim, ppl[12], last[12];

struct QN {
	int cap, f, u, ser, cur;

	bool operator<(const QN & a)const {
		if (a.cur == cur)
			return a.ser > ser;
		return a.cur < cur;
	}
};

int get_next(int u) {
	if (last[u] == -1)return (u + 1) % n;
	if ((last[u] + 1) % n == u)
		return (last[u] + 2) % n;
	return (last[u] + 1) % n;
}

int main() {
	while (scanf("%s", ncase), strcmp(ncase, "TheEnd") != 0) {

		scanf("%d%d%d", &n, &s, &t);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == i)dis[i][j] = 0;
				else
					scanf("%d", &dis[i][j]);
			}
		}
		int sum = 0;
		for (int i = 1; i < n; i++) {
			scanf("%d", ppl + i);
			sum += ppl[i];
		}
		scanf("%d", &tim);
		memset(last, -1, sizeof (last));

		int x = 0, k = 1;
		QN now, tem;
		priority_queue<QN>Q;
		map<int, int>mp;
		map<int, int>::iterator p, q;
		now.u = 1;
		now.f = 0;
		now.ser = dis[0][1];
		now.cur = dis[0][1];
		now.cap = s > 3 ? s : 3;
		last[0] = 1;
		Q.push(now);
		while (!Q.empty()) {
			now = Q.top();
			Q.pop();
			int cur = now.cur;
			int u = now.u;
			if (!mp.empty()) {
				p = mp.begin();
				int flag = 0;
				while (p->first < cur && p != mp.end()) {
					last[0] = get_next(0);
					tem.u = last[0];
					tem.f = 0;
					tem.ser = 0;
					tem.cur = p->first + dis[0][tem.u];
					tem.cap = s - ((++k) - 1) * t;
					if (3 > tem.cap)tem.cap = 3;
					Q.push(tem);
					q = p++;
					mp.erase(q);
					flag = 1;
				}
				if (flag) {
					Q.push(now);
					continue;
				}
			}
			if (cur > tim)break;
			if (u == 0) {
				x += now.f;
				if (x == sum)break;
				now.f = 0;
				now.u = get_next(0);
				tem.cur += dis[0][now.u];
				tem.ser += dis[0][now.u];
				continue;
			}
			if (now.f + ppl[u] > now.cap) {
				mp[now.cur + 2] = 1;
				ppl[u] -= (now.cap - now.f);
				now.f = now.cap;
				now.u = 0;
				now.cur += dis[u][0];
				now.ser += dis[u][0];
				Q.push(now);
				last[u] = 0;
			} else {
				now.f += ppl[u];
				ppl[u] = 0;
				if (now.f == now.cap) {
					now.u = 0;
					now.cur += dis[u][0];
					now.ser += dis[u][0];
					Q.push(now);
					last[u] = 0;
				} else {
					now.u = get_next(u);
					now.cur += dis[u][now.u];
					now.ser += dis[u][now.u];
					Q.push(now);
					last[u] = now.u;
				}
			}
		}
		puts(ncase);
		if (x == sum)printf("%d seconds needed\n", now.cur);
		else printf("%d contestants reached\n", x);
	}
	return 0;
}