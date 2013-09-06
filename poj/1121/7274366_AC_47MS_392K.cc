#include <cstdio>
#include <cstring>

struct edge {
	int to;
	edge *next;
} edg[50010], *vert[50];

char str[30];
bool flag[2][50][30];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];
	vert[x] = p;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {

		memset(flag, 0, sizeof (flag));
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			if (strcmp(str, ".") != 0) {
				int len = strlen(str);
				for (int j = 0; j < len; j++) {
					flag[0][i][str[j] - 'A'] = true;
				}
			}
			scanf("%s", str);
			if (strcmp(str, ".") != 0) {
				int len = strlen(str);
				for (int j = 0; j < len; j++) {
					flag[1][i][str[j] - 'A'] = true;
				}
			}
		}
		int top = -1, x, y;
		memset(vert, 0, sizeof (vert));
		while (scanf("%d%d", &x, &y), x || y) {
			add_edge(x, y, top);
		}
		while (1) {
			bool ff = true;
			for (int i = 1; i <= n; i++) {
				for (edge *p = vert[i]; p; p = p->next) {
					int to = p->to;
					for (int k = 0; k < 26; k++) {
						if (flag[0][i][k] && !flag[0][to][k] && !flag[1][to][k]) {
							ff = false;
							flag[0][to][k] = 1;
						}
					}
				}
			}
			if (ff)break;
		}
		for (int i = 1; i <= n; i++) {
			printf(":");
			for (int j = 0; j < 26; j++) {
				if (flag[0][i][j]) {
					printf("%c", j + 'A');
				}
			}
			printf(":\n");
		}
	}
	return 0;
}
