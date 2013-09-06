#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

char str[102], tem[102];
const int inf = 1000000000;
int n, m, dis[12][12];

struct node {
	int host, id, d;

	bool operator<(const node & a)const {
		if (a.host == host) {
			return a.id > id;
		}
		return a.host > host;
	}
} nod[1000010];

void solve() {
	map <string, int> island;
	map <string, int> ::iterator p;

	map <int, int> host;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dis[i][j] = inf;
		}
		dis[i][i] = 0;
	}
	for (int id = 0, i = 0; i < n; i++) {
		int u, v, d;
		scanf("%s%d", str, &m);
		p = island.find(str);
		if (p == island.end()) {
			island.insert(make_pair(str, id));
			u = id++;
		} else u = p->second;

		for (int j = 0; j < m; j++) {
			scanf("%s", tem);
			if (tem[0] == 'T') {
				scanf("%d%s", &d, str);
				p = island.find(str);
				if (p == island.end()) {
					island.insert(make_pair(str, id));
					v = id++;
				} else v = p->second;
				if (dis[u][v] > d)dis[u][v] = d;
			} else {
				scanf("%d", &d);
				host[d] = u;
			}
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (dis[i][k] != inf) {
				for (int j = 0; j < n; j++) {
					if (dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}
	}
	scanf("%d", &m);

	map <int, int> mp[30], group;
	map <int, int> ::iterator q, pos;

	int top = 0, xx = 0;
	for (int i = 0; i < m; i++) {
		int id, gg, tt, dd, code;
		scanf("%s%d%d", str, &id, &gg);
		if (str[0] == 'J') {
			pos = group.find(gg);
			if (pos == group.end()) {
				group[gg] = xx++;
				tt = xx - 1;
			} else tt = pos->second;
			mp[tt].insert(make_pair(id, 1));
		} else if (str[0] == 'L') {
			tt = group.find(gg)->second;
			q = mp[tt].find(id);
			mp[tt].erase(q);
		} else {
			scanf("%d%d", &code, &dd);
			tt = group.find(gg)->second;
			int u = host.find(id)->second, v;
			for (q = mp[tt].begin(); q != mp[tt].end(); q++) {
				v = host.find(q->first)->second;
				if (dis[u][v] <= dd) {
					nod[top].host = q->first;
					nod[top].id = code;
					nod[top].d = dd - dis[u][v];
					top++;
				}
			}
		}
	}
	sort(nod, nod + top);
	for (int i = 0; i < top; i++) {
		printf("%d %d %d\n", nod[i].host, nod[i].id, nod[i].d);
	}
	puts("");
	return;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca = 1;
	while (scanf("%d", &n), n) {
		printf("Network #%d\n", nca++);
		solve();
	}
	return 0;
}
