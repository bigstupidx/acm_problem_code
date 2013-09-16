#include <cstdio>
#include <cstring>

using namespace std;

int n, m, s, f;

int main() {
	while (scanf("%d%d%d%d", &n, &m, &s, &f) != EOF) {
		int start_time = 1, tt, ll, rr;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &tt, &ll, &rr);
			if (s == f)
				continue;
//			printf("%d %d %d\n", s, f, start_time);
			if (s < f) {
				if (tt > start_time) {
					for (int j = start_time; j < tt; j++) {
						putchar('R');
						if (++s == f)
							break;
					}
					start_time = tt;
				}
				if (s != f) {
					if (s + 1 < ll || s > rr) {
						putchar('R');
						++s;
						++start_time;
					} else {
						putchar('X');
						++start_time;
					}
				}
			} else {
				if (tt > start_time) {
					for (int j = start_time; j < tt; j++) {
						putchar('L');
						if (--s == f)
							break;
					}
					start_time = tt;
				}
				if (s != f) {
					if (s < ll || s - 1 > rr) {
						putchar('L');
						--s;
						++start_time;
					} else {
						putchar('X');
						++start_time;
					}
				}
			}
		}
		if (s != f) {
			if (s < f)
				for (int i = s; i < f; i++)
					putchar('R');
			else
				for (int i = f; i < s; i++)
					putchar('L');
		}
		puts("");
	}
	return 0;
}
