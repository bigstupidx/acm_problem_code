#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

char str[1002], ch;
bool flag[32][32];
int n, d, s;

struct lines {
	int cnt, arr[52];
} line[22];

struct drivers {
	int li, ii;
} dri[32];

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d%d", &n, &d, &s), n || d || s) {

		while ((ch = getchar()) != '\n');

		for (int i = 0; i < n; i++) {

			gets(str);
			string st(str);
			istringstream in(st);
			int m = 0, si, di;
			while (in >> line[i].arr[m])m++;
			line[i].cnt = m;

			gets(str);
			string st1(str);
			istringstream in1(st1);
			while (in1 >> si) {
				in1 >> di;
				dri[di].li = i;
				for (int j = 0; j < m; j++) {
					if (si == line[i].arr[j]) {
						dri[di].ii = j;
						break;
					}
				}
			}
		}
		memset(flag, 0, sizeof (flag));
		for (int i = 0; i < 100; i++) {
			for (int j = 1; j <= d; j++) {
				int j1 = dri[j].li, j2 = dri[j].ii;
				//printf("%d ", line[j1].arr[j2]);
				for (int k = 1; k <= d; k++) {
					int k1 = dri[k].li, k2 = dri[k].ii;
					if (line[j1].arr[j2] == line[k1].arr[k2]) {
						flag[j][k] = 1;
						for (int ll = 1; ll <= d; ll++) {
							if (flag[j][ll] || flag[k][ll]) {
								flag[j][ll] = 1;
								flag[k][ll] = 1;
							}
						}
					}
				}
			}
			//puts("");
			int xflag = 0;
			for (int j = 1; j <= d && !xflag; j++) {
				for (int k = 1; k <= d; k++) {
					if (j != k && !flag[j][k]) {
						xflag = 1;
						break;
					}
				}
			}
			if (!xflag)break;
			for (int j = 1; j <= d; j++) {
				dri[j].ii = (dri[j].ii + 1) % line[dri[j].li].cnt;
			}
		}
		int xflag = 0;
		for (int i = 1; i <= d; i++) {
			for (int j = 1; j <= d; j++) {
				if (i != j && !flag[i][j]) {
					xflag = 1;
					//printf("%d %d\n", i, j);
					break;
				}
			}
		}
		if (!xflag)puts("Yes");
		else puts("No");
	}
	return 0;
}
