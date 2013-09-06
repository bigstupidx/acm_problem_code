#include <cstdio>
#include <cstring>

int n, flag[300], deg[300], par[300];

bool is_alp(char ch) {
	if (ch >= 'a' && ch <= 'z')return true;
	if (ch >= 'A' && ch <= 'Z')return true;
	return false;
}

int find(int x) {
	if (par[x] == -1)return x;
	return par[x] = find(par[x]);
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (1) {
		char ch;
		while ((ch = getchar()) != EOF && ch != '{');
		if (ch == EOF)break;
		memset(par, -1, sizeof (par));
		memset(deg, 0, sizeof (deg));
		memset(flag, 0, sizeof (flag));
		int m = 0, xx = 1;
		while ((ch = getchar()) != '}') {
			if (is_alp(ch) && !flag[ch]) {
				flag[ch] = 1;
				m++;
			}
		}
		while ((ch = getchar()) != '{');
		while (1) {
			while ((ch = getchar()) != '(' && ch != '}');
			if (ch == '}')break;
			int pre = -1, next = -1;
			while ((ch = getchar()) != ')') {
				if (is_alp(ch)) {
					if (pre == -1)pre = ch;
					else if (next == -1) {
						next = ch;
						//printf("%c -> %c\n", pre, next);
						deg[pre]++, deg[next]++;
						int ii = find(pre);
						int jj = find(next);
						if (ii != jj) {
							par[ii] = jj;
							xx++;
						}
						pre = -1, next = -1;
					}
				}
			}
		}
		if (m != 1) {
			int yy = 0;
			for (int i = 0; i < 300; i++) {
				if (flag[i] && deg[i] == 0) {
					yy++;
				}
			}
			if (xx != m - yy)puts("No No");
			else {
				int cnt = 0;
				for (int i = 0; i < 300; i++) {
					cnt += deg[i] % 2;
				}
				if (cnt == 2)puts("Yes No");
				else puts("No Yes");
			}
		} else {
			int cnt = 0;
			for (int i = 0; i < 300; i++) {
				cnt += deg[i] % 2;
			}
			if (cnt == 2)puts("Yes No");
			else puts("No Yes");
		}
	}
	return 0;
}
