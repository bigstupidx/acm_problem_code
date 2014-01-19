#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

char str[55][55], ch;
int n, m, w, h, k, flag[32], my[32], g[32][32];

bool path(int s) {
	for (int i = 0; i < 26; i++) {
		if (!flag[i] && g[s][i]) {
			flag[i] = 1;
			if (my[i] == -1 || path(my[i])) {
				my[i] = s;
				return true;
			}
		}
	}
	return false;
}

int max_match() {
	int ans = 0;
	memset(my, -1, sizeof (my));
	for (int i = 0; i < k; i++) {
		memset(flag, 0, sizeof (flag));
		if (path(i))++ans;
	}
	return ans;
}

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		scanf("%d%d%d%d%d", &k, &n, &m, &h, &w);
		int ans = 0;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%s", str[j]);
			}
			vector <int> ins;
			bool xflag = 0;
			for (int ii = 0; ii <= n - h; ii++) {
				for (int jj = 0; jj <= m - w; jj++) {
					int cnt = 0;
					memset(flag, 0, sizeof (flag));
					for (int ix = ii; ix < ii + h; ix++) {
						for (int jy = jj; jy < jj + w; jy++) {
							if (str[ix][jy] != '0') {
								if (!flag[str[ix][jy] - 'A']) {
									++cnt;
									flag[str[ix][jy] - 'A'] = 1;
									ch = str[ix][jy];
								}
							}
						}
					}
					if (cnt == 0)xflag = 1;
					else if (cnt == 1) {
						ins.push_back(ch - 'A');
					}
				}
			}
			if (xflag)++ans;
			else {
				for (int j = 0; j < ins.size(); ++j) {
					g[i][ins[j]] = 1;
				}
			}
		}
		printf("%d\n", ans + max_match());
	}
	return 0;
}
