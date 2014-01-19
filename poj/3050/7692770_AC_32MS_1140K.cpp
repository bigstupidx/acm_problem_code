#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

int gg[5][5], path[7], ans;
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
bool mark[1000000];

void DFS(int i, int j, int depth) {
	if (depth == 6) {
		int num = 0;
		for (int k = 0; k < 6; k++) {
			num = num * 10 + path[k];
		}
		if (!mark[num]) {
			mark[num] = true;
			++ans;
		}
		return;
	}
	path[depth] = gg[i][j];
	for (int k = 0; k < 4; k++) {
		int ii = i + dir[k][0];
		int jj = j + dir[k][1];
		if (ii < 0 || ii == 5 || jj < 0 || jj == 5)continue;
		DFS(ii, jj, depth + 1);
	}
	return;
}

int main() {
	memset(mark, 0, sizeof (mark));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &gg[i][j]);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			DFS(i, j, 0);
		}
	}
	//	for (p = st.begin(); p != st.end(); ++p) {
	//		printf("%d ", *p);
	//	}
	//	puts("");
	printf("%d\n", ans);
	return 0;
}

