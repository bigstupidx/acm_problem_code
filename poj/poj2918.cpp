#include <cstdio>
#include <cstring>

int map[9][9], arr[100], top;
bool flag[10];
char str[12];

bool fill(int pos_i, int pos_j) {
	memset(flag, 0, sizeof(flag));
	for (int i = 0; i < 9; i++) {
		flag[map[i][pos_j]] = true;
		flag[map[pos_i][i]] = true;
	}
	int temp_i = (pos_i / 3) * 3;
	int temp_j = (pos_j / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			flag[map[temp_i + i][temp_j + j]] = true;
		}
	}
	int count = 0, xx;
	for (int i = 1; i < 10; i++) {
		if (!flag[i]) {
			++count;
			xx = i;
		}
	}
	if (count != 1)
		return false;
	map[pos_i][pos_j] = xx;
	return true;
}

int main() {
	int nca;
	scanf("%d", &nca);
	for (int ii = 1; ii <= nca; ii++) {
		top = 0;
		for (int i = 0; i < 9; i++) {
			scanf("%s", str);
			for (int j = 0; j < 9; j++) {
				map[i][j] = str[j] - '0';
				if (map[i][j] == 0) {
					arr[top++] = i * 9 + j;
				}
			}
		}

		while (top > 0) {
			int x_pos = -1;
			for (int i = 0; i < top; i++) {
				if (fill(arr[i] / 9, arr[i] % 9)) {
					x_pos = i;
					break;
				}
			}
			arr[x_pos] = arr[top - 1];
			--top;
		}
		printf("Scenario #%d:\n", ii);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%c", map[i][j] + '0');
			}
			puts("");
		}
		puts("");
	}
	return 0;
}
