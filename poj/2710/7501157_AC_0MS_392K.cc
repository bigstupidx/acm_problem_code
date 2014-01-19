#include <cstdio>
#include <cstring>

using namespace std;

int arr[300], aa[300];

int main() {
	//freopen("in.txt", "r", stdin);
	int nca;
	scanf("%d", &nca);
	for (int ii = 1; ii <= nca; ii++) {
		int n, d, s, t;
		scanf("%d%d%d%d", &n, &d, &s, &t);
		printf("Problem set %d: %d / %d, base 7 digits %d through %d: ", ii, n, d, s, t);
		int lf = 0, x = n, y = d;
		x %= y;
		memset(arr, 0, sizeof(arr));
		while (lf < 260) {
			arr[lf] = x / y;
			x %= y;
			x *= 7;
			lf++;
		}
		s++, t++;
		for (int i = s; i <= t; i++) {
			printf("%d", arr[i]);
		}
		puts("");
	}
	return 0;
}
