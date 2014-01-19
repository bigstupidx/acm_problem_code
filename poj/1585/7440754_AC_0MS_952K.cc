#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

char str[10002];
const int inf = 1000000000;
int n, m, flag[10002], cnt[10002], mark[10002];

vector <int> vote[10002];

void solve() {
	map <string, int> mp;
	map <string, int> ::iterator p;

	map <int, string> name;

	int id = 0;
	for (int v, i = 0; i < m; i++) {
		gets(str);
		string st(str);
		istringstream in(st);
		vote[i].clear();
		while (in >> str) {
			p = mp.find(str);
			if (p == mp.end()) {
				name.insert(make_pair(id, str));
				mp[str] = id++;
				v = id - 1;
			} else v = p->second;
			vote[i].push_back(v);
		}
	}
	memset(mark, 0, sizeof (mark));
	memset(flag, 0, sizeof (flag));
	while (1) {
		for (int i = 0; i < n; i++) {
			cnt[i] = 0;
		}
		int x = 0, xflag = 0;
		for (int i = 0; i < m; i++) {
			if (mark[i])continue;
			xflag = 0;
			for (int j = 0; j < vote[i].size(); j++) {
				if (!flag[vote[i][j]]) {
					xflag = 1;
					x++;
					cnt[vote[i][j]]++;
					break;
				}
			}
			if (!xflag)mark[i] = 1;
		}
		int mini = inf, maxi = -1;
		for (int i = 0; i < n; i++) {
			if (flag[i])continue;
			if (cnt[i]>x / 2) {
				cout << name.find(i)->second << " won" << endl;
				return;
			} else {
				if (mini > cnt[i]) {
					mini = cnt[i];
				}
				if (maxi < cnt[i]) {
					maxi = cnt[i];
				}
			}
		}
		if (maxi == mini) {
			int i = 0;
			printf("it is a tie between ");
			while (flag[i])i++;
			cout << name.find(i)->second;
			for (++i; i < n; i++) {
				if (!flag[i]) {
					cout << " and " << name.find(i)->second;
				}
			}
			puts("");
			return;
		}
		for (int i = 0; i < n; i++) {
			if (cnt[i] == mini) {
				flag[i] = 1;
			}
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m), n || m) {
		getchar();
		solve();
	}
	return 0;
}