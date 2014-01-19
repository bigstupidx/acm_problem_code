#include <cstdio>
#include <cstring>

char str[4];
int n, g[60][60], flag[60], my[60], va[2][60];

int get_num(char ch) {
	if (ch >= '2' && ch <= '9')return ch - '0';
	if (ch == 'T')return 10;
	if (ch == 'J')return 11;
	if (ch == 'Q')return 12;
	if (ch == 'K')return 13;
	if (ch == 'A')return 14;
	if (ch == 'C')return 0;
	if (ch == 'D')return 1;
	if (ch == 'S')return 2;
	if (ch == 'H')return 3;
}

int get_value() {
	int ans = get_num(str[0]);
	ans = ans * 4 + get_num(str[1]);
	return ans;
}

bool path(int s) {
	for (int i = 0; i < n; i++) {
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
	for (int i = 0; i < n; i++) {
		memset(flag, 0, sizeof (flag));
		if (path(i))ans++;
	}
	return ans;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		scanf("%d", &n);
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < n; i++) {
				scanf("%s", str);
				va[j][i] = get_value();
			}
		}
		memset(g, 0, sizeof (g));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (va[1][i] > va[0][j]) {
					g[i][j] = 1;
				}
			}
		}
		printf("%d\n", max_match());
	}
	return 0;
}
