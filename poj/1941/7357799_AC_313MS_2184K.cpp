#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

char ans[1024][2048];
int n, fic[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 4048};

void solve(int n) {
	if (n == 1) {
		memset(ans, 0, sizeof (ans));
		strcpy(ans[1023], "/__\\");
		strcpy(ans[1022], " /\\ ");
	} else {
		solve(n - 1);
		int x = fic[n];
		int y = fic[n - 1];
		for (int i = 1024 - y; i < 1024; i++) {
			for (int j = x; j < 2 * x; j++) {
				ans[i][j] = ans[i][j - x];
			}
		}
		//puts(ans[1022]);
		//puts(ans[1023]);
		for (int i = 1024 - 2 * y; i < 1024 - y; i++) {
			for (int j = y; j < y + x; j++) {
				ans[i][j] = ans[i + y][j - y];
			}
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d", &n), n) {
		solve(n);
		int y = 1 + fic[n];
		for (int i = 1024 - fic[n]; i < 1024; i++) {
			for (int j = 0; j < y; j++) {
				if (ans[i][j] == 0) {
					putchar(' ');
				}
				else putchar(ans[i][j]);
			}
			puts("");
			y++;
		}
		puts("");
	}
	return 0;
}
