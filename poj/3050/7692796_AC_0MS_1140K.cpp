#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
bool mark[999999];
int num[6];
int ans;
int map[5][5];
int turn[4][2] = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

void dfs(int i, int j, int depth) {
	int a;
	if (depth == 6) {
		a = 10 * (10 * (10 * (10 * (10 * num[0] + num[1]) + num[2]) + num[3]) + num[4]) + num[5];
		if (!mark[a])ans++, mark[a] = 1;
		return;
	}
	for (int k = 0; k < 4; k++) {
		int x = i + turn[k][0];
		int y = j + turn[k][1];
		if (x >= 0 && x < 5 && y >= 0 && y < 5) {
			num[depth] = map[x][y];
			dfs(x, y, depth + 1);
		}
	}
	return;
}

int main() {
	int i, j;
	//	while (1) {
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
			scanf("%d", &map[i][j]);
	}
	memset(mark, 0, sizeof (mark));
	ans = 0;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			dfs(i, j, 0);

	printf("%d\n", ans);
	//	}
	return 0;
}