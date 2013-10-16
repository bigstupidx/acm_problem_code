#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int get_ans(long long n, long long x, long long y) {
	if (n == 1) {
		if (x == 1 && y == 1)return -1;
		return 1;
	}
	long long m = n / 2;
	if (x >= m && y >= m)return -1 * get_ans(m, x - m, y - m);
	if (x >= m)return get_ans(m, x - m, y);
	if (y >= m)return get_ans(m, x, y - m);
	return get_ans(m, x, y);
}

int main() {
	//freopen("small.in", "r", stdin);
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		long long n, x, y, w, h;
		cin >> n >> x >> y >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				printf("%d ", get_ans(n, y + i, x + j));
			}
			puts("");
		}
		puts("");
	}
	return 0;
}
