#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

char str[40];

struct Mpnode {
	char str[40];

	bool operator<(const Mpnode & a)const {
		return strcmp(a.str, str) < 0;
	}
} now;

int n, m, f[102][102], pos[102][102][2], flag[102], arr[2][102];

void solve() {
	map <Mpnode, int> mp;
	map <Mpnode, int> ::iterator p;
	map <int, Mpnode> name;
	map <int, Mpnode> ::iterator q;
	n = 0, m = 0;
	int id = 1;
	if (strcmp(str, "#") != 0) {
		strcpy(now.str, str);
		mp.insert(make_pair(now, 0));
		name.insert(make_pair(0, now));
		arr[0][++n] = 0;
		while (scanf("%s", now.str), strcmp(now.str, "#") != 0) {
			p = mp.find(now);
			if (p == mp.end()) {
				mp.insert(make_pair(now, id));
				name.insert(make_pair(id, now));
				arr[0][++n] = id++;
			}
			else {
				arr[0][++n] = p->second;
			}
		}
	}
	while (scanf("%s", now.str), strcmp(now.str, "#") != 0) {
		p = mp.find(now);
		if (p == mp.end()) {
			mp.insert(make_pair(now, id));
			name.insert(make_pair(id, now));
			arr[1][++m] = id++;
		}
		else {
			arr[1][++m] = p->second;
		}
	}
	//	for (int i = 1; i <= n; i++) {
	//		printf("%d ", arr[0][i]);
	//	}
	//	puts("");
	//	for (int i = 1; i <= m; i++) {
	//		printf("%d ", arr[1][i]);
	//	}
	//	puts("");
	memset(f, 0, sizeof (f));
	memset(pos, -1, sizeof (pos));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (f[i][j - 1] > f[i - 1][j]) {
				f[i][j] = f[i][j - 1];
				pos[i][j][0] = i;
				pos[i][j][1] = j - 1;
			}
			else {
				f[i][j] = f[i - 1][j];
				pos[i][j][0] = i - 1;
				pos[i][j][1] = j;
			}
			if (arr[0][i] == arr[1][j] && f[i - 1][j - 1] + 1 > f[i][j]) {
				f[i][j] = f[i - 1][j - 1] + 1;
				pos[i][j][0] = i - 1;
				pos[i][j][1] = j - 1;
			}
		}
	}
	memset(flag, 0, sizeof (flag));
	int i = n, j = m;
	//printf("%d\n", f[n][m]);
	while (pos[i][j][0] != -1) {
		int ii = pos[i][j][0];
		int jj = pos[i][j][1];
		if (f[ii][jj] != f[i][j]) {
			flag[i] = 1;
		}
		i = ii, j = jj;
	}
	for (int i = 1; i <= n; i++) {
		if (flag[i]) {
			q = name.find(arr[0][i]);
			printf("%s ", (q->second).str);
		}
	}
	puts("");
	return;
}

int main() {
	while (scanf("%s", str) != EOF) {
		solve();
	}
	return 0;
}
