#include <cstdio>
#include <cstring>

int n, m;
char map[80][80], str[20], txt[22];

void drawline(int x1, int y1, int x2, int y2) {
	int temp;
	if (y1 == y2) {
		if (x1 > x2) {
			temp = x1, x1 = x2, x2 = temp;
		}
		for (int i = x1; i <= x2; i++) {
			if (map[i][y1] == '|' || map[i][y1] == ' ')map[i][y1] = '|';
			else if (map[i][y1] == '-' || map[i][y1] == '+') {
				map[i][y1] = '+';
			}
			else map[i][y1] = '*';
		}
	}
	else if (x1 == x2) {
		if (y1 > y2) {
			temp = y1, y1 = y2, y2 = temp;
		}
		for (int j = y1; j <= y2; j++) {
			if (map[x1][j] == '-' || map[x1][j] == ' ') {
				map[x1][j] = '-';
			}
			else if (map[x1][j] == '|' || map[x1][j] == '+') {
				map[x1][j] = '+';
			}
			else map[x1][j] = '*';
		}
	}
	else if (x2 - x1 == y2 - y1) {
		if (x1 > x2) {
			temp = x1, x1 = x2, x2 = temp;
			temp = y1, y1 = y2, y2 = temp;
		}
		for (int i = x1, j = y1; i <= x2; i++, j++) {
			if (map[i][j] == ' ' || map[i][j] == '\\') {
				map[i][j] = '\\';
			}
			else if (map[i][j] == '/' || map[i][j] == 'x') {
				map[i][j] = 'x';
			}
			else map[i][j] = '*';
		}
	}
	else {
		if (x1 > x2) {
			temp = x1, x1 = x2, x2 = temp;
			temp = y1, y1 = y2, y2 = temp;
		}
		for (int i = x1, j = y1; i <= x2; i++, j--) {
			if (map[i][j] == ' ' || map[i][j] == '/') {
				map[i][j] = '/';
			}
			else if (map[i][j] == 'x' || map[i][j] == '\\') {
				map[i][j] = 'x';
			}
			else map[i][j] = '*';
		}
	}
}

void my_output() {
	printf("+");
	for (int i = 1; i <= n; i++)printf("-");
	printf("+\n");
	for (int i = 1; i <= m; i++) {
		printf("|");
		for (int j = 1; j <= n; j++) {
			printf("%c", map[i][j]);
		}
		printf("|\n");
	}
	printf("+");
	for (int i = 1; i <= n; i++)printf("-");
	printf("+\n");
}

int main() {
	while (scanf("%d%d", &n, &m), n || m) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = ' ';
			}
		}
		while (scanf("%s", str), strcmp(str, "PRINT") != 0) {
			int x1, x2, y1, y2, temp;
			scanf("%d%d", &y1, &x1);
			if (strcmp(str, "POINT") == 0) {
				if (map[x1][y1] == ' ' || map[x1][y1] == 'o') {
					map[x1][y1] = 'o';
				}
				else map[x1][y1] = '*';
			}
			else if (strcmp(str, "TEXT") == 0) {
				scanf("%s", txt);
				int len = strlen(txt);
				for (int i = 0; i < len && y1 + i < n + 1; i++) {
					if (map[x1][y1 + i] != ' ' && map[x1][y1 + i] != txt[i]) {
						map[x1][y1 + i] = '*';
					}
					else map[x1][y1 + i] = txt[i];
				}
			}
			else if (strcmp(str, "LINE") == 0) {
				scanf("%d%d", &y2, &x2);
				drawline(x1, y1, x2, y2);
			}
			else {
				scanf("%d%d", &y2, &x2);
				if (x1 > x2) {
					temp = x1, x1 = x2, x2 = temp;
				}
				if (y1 > y2) {
					temp = y1, y1 = y2, y2 = temp;
				}
				for (int i = x1; i <= x2; i++) {
					for (int j = y1; j <= y2; j++) {
						map[i][j] = ' ';
					}
				}
			}
		}
		my_output();
		puts("");
	}
	return 0;
}
