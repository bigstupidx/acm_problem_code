#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int n, m, gg[130][130], cnt[130];

void bronkerbosch(vector <int> r, vector <int> p, vector <int> x) {
	//	for (int i = 0; i < r.size(); i++) {
	//		printf("%d ", r[i]);
	//	}
	//	puts("");
	//	for (int j = 0; j < p.size(); j++) {
	//		printf("%d ", p[j]);
	//	}
	//	puts("");
	if (p.size() == 0 && x.size() == 0) {
		//		for (int i = 0; i < r.size(); i++) {
		//			printf("%d ", r[i]);
		//		}
		//		puts("");
		return;
	}
	cnt[r.size()]++;
	bool visit[130];
	memset(visit, 0, sizeof (visit));
	for (int i = 0; i < p.size(); i++) {
		if (!visit[p[i]]) {
			vector <int> rr, pp, xx;
			for (int j = 0; j < r.size(); j++) {
				rr.push_back(r[j]);
			}
			rr.push_back(p[i]);
			for (int j = i + 1; j < p.size(); j++) {
				bool xflag = 0;
				for (int k = 0; k < rr.size(); k++) {
					if (!gg[p[j]][rr[k]]) {
						xflag = 1;
						break;
					}
				}
				if (!xflag) {
					visit[j] = 1;
					pp.push_back(p[j]);
				}
			}
			bronkerbosch(rr, pp, xx);
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(gg, 0, sizeof (gg));
		memset(cnt, 0, sizeof (cnt));
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			gg[x][y] = gg[y][x] = 1;
		}
		vector <int> r, p, x;
		r.clear(), x.clear();
		for (int i = 1; i <= n; i++) {
			p.push_back(i);
		}
		bronkerbosch(r, p, x);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (cnt[i] != 0 && cnt[i + 1] == 0) {
				ans = cnt[i];
				break;
			}
		}
		if (ans > 1000)puts("Too many maximal sets of friends.");
		else printf("%d\n", ans);
	}
	return 0;
}
