#include <cstdio>
#include <cstring>

char aa[5], bb[5];

char str[4][4] = { "R", "U", "L", "D" };

int i1, i2, j1, j2;

int xabs(int x) {
	return x > 0 ? x : -x;
}
void solve() {
	int xx = xabs(i1 - i2);
	int yy = xabs(j1 - j2);

	int mini = xx > yy ? yy : xx;
	int maxi = xx > yy ? xx : yy;
	printf("%d\n", maxi);

	if (i1 < i2) {
		if (j1 < j2) {
			for (int i = 0; i < mini; i++) {
				puts("RU");
			}
			int index = i2 - i1 == maxi ? 0 : 1;
			for (int i = mini; i < maxi; i++) {
				puts(str[index]);
			}
		} else {
			for (int i = 0; i < mini; i++) {
				puts("RD");
			}
			int index = i2 - i1 == maxi ? 0 : 3;
			for (int i = mini; i < maxi; i++) {
				puts(str[index]);
			}
		}
	} else {
		if (j1 < j2) {
			for (int i = 0; i < mini; i++) {
				puts("LU");
			}
			int index = i1 - i2 == maxi ? 2 : 1;
			for (int i = mini; i < maxi; i++) {
				puts(str[index]);
			}
		} else {
			for (int i = 0; i < mini; i++) {
				puts("LD");
			}
			int index = i1 - i2 == maxi ? 2 : 3;
			for (int i = mini; i < maxi; i++) {
				puts(str[index]);
			}
		}
	}
}

int main() {
	while (scanf("%s%s", aa, bb) != EOF) {
		i1 = aa[0] - 'a';
		j1 = aa[1] - '1';

		i2 = bb[0] - 'a';
		j2 = bb[1] - '1';
		solve();
	}
	return 0;
}
