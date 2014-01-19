#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

char str[22];
int n, s, t, tim, ppl[12], dis[12][12], last[12];

struct QN {
	int u; //到达的当前节点标号
	int f; //到达当前节点时车的容量c
	int c; //到达当前节点时车上已经有的人数f
	int cur, ser; //到达当前节点时间 服务时间

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
		memset(last, -1, sizeof (last));

		QN now, tem;
		priority_queue<QN>Q;
		map<int, int>mp;
		map<int, int>::iterator p, q;
		now.u = 1;
		now.c = s;
		now.f = 0;
		now.cur = dis[0][1];
		now.ser = dis[0][1];
		Q.push(now);
		last[0] = 1;
		int k = 1, x = 0;
		while (!Q.empty()) {
			now = Q.top();
			Q.pop();
			int u = now.u;
			int cur = now.cur;
			if (!mp.empty()) {
				int flag = 0;
				for (p = mp.begin(); p != mp.end();) {
					if (p->first < cur) {
						flag = 1;
						tem.u = get_next(0);
						tem.c = s - k * t;
						tem.f = 0;
						tem.cur = p->first + dis[0][tem.u];
						tem.ser = dis[0][tem.u];
						Q.push(tem);
						last[0] = tem.u;
						q = p++;
						mp.erase(q);
						k++;
					} else break;
				}
				if (flag) {
					Q.push(now);
					continue;
				}
			}
//			printf("%d %d %d\n", u, cur, now.f);
			if (cur > tim)break;
			if (u == 0) {
				x += now.f;
				if (x == sum)break;
				now.u = get_next(0);
				now.f = 0;
				now.cur += dis[0][now.u];
				if(now.cur>tim)continue;
				now.ser += dis[0][now.u];
				Q.push(now);
				last[0] = now.u;
			} else {
				if (now.f + ppl[u] > now.c) {
					mp[cur + 2] = 1;
					ppl[u] -= now.c - now.f;
					now.u = 0;
					now.f = now.c;
					now.cur += dis[u][0];
					if(now.cur>tim)continue;
					now.ser += dis[u][0];
					Q.push(now);
					last[u] = 0;
				} else {
					now.f += ppl[u];
					ppl[u] = 0;
					if (now.f == now.c) {
						now.u = 0;
						now.cur += dis[u][0];
						if(now.cur>tim)continue;
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
		}
		if(sum==x)
			printf("%d seconds needed\n", now.cur);
		else
			printf("%d contestants reached\n", x);
	}
	return 0;
}