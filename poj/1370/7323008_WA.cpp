#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

char str[300];
int n, d, s, g[32][32], bus[22][22], ppl[22][22];

bool intersect(int ii, int jj) {
	for (int i = 1; i < bus[ii][0]; i++) {
		for (int j = 1; j < bus[jj][0]; j++) {
			if (bus[ii][i] == bus[jj][j]) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	while (scanf("%d%d%d", &n, &d, &s), n || d || s) {
		getchar();
		for (int tem, i = 0; i < n; i++) {
			bus[i][0] = 1;
			ppl[i][0] = 1;

			gets(str);
			string st(str);
			istringstream in(st);
			while (in >> bus[i][bus[i][0]])bus[i][0]++;

			gets(str);
			string st1(str);
			istringstream in1(st1);
			while (in1 >> tem) {
				in1 >> ppl[i][ppl[i][0]];
				ppl[i][0]++;
			}
		}
		memset(g, 0, sizeof (g));
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (bus[i][0] % 2 && bus[j][0] % 2 == 0 || bus[i][0] % 2 == 0 && bus[j][0] % 2) {
					if (intersect(i, j)) {
						for (int k1 = 1; k1 < ppl[i][0]; k1++) {
							for (int k2 = 1; k2 < ppl[j][0]; k2++) {
								g[ppl[i][k1]][ppl[j][k2]] = 1;
								g[ppl[j][k2]][ppl[i][k1]] = 1;
							}
						}
					}
				}
			}
		}
		for (int k = 1; k <= d; k++) {
			for (int i = 1; i <= d; i++) {
				if (g[i][k]) {
					for (int j = 1; j <= d; j++) {
						if (g[k][j]) {
							g[i][j] = 1;
						}
					}
				}
			}
		}
		int xflag = 0;
		for (int i = 1; i <= d && !xflag; i++) {
			for (int j = 1; j <= d; j++) {
				if (i != j && g[i][j] == 0) {
					xflag = 1;
					break;
				}
			}
		}
		if (xflag)puts("No");
		else puts("Yes");
	}
	return 0;
}

