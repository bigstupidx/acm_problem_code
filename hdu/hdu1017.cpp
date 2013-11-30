#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n, m, arr[102];

void pre_done() {
	for (int i = 0; i < 101; i++) {
		arr[i] = i * i;
	}
}

int main() {

	pre_done();

	int nca;
	scanf("%d", &nca);

	for (int ica = 0; ica < nca; ica++) {

		if (ica != 0)
			puts("");

		int ii = 1;
		while (scanf("%d%d", &n, &m) != EOF) {
			if (n == 0 && m == 0)
				break;
			int ans = 0;
			for (int i = 1; i < n; i++) {
				for (int j = 1; j < i; j++) {
					int temp = arr[i] + arr[j] + m;
					if (temp % (i * j) == 0) {
						++ans;
					}
				}
			}
			printf("Case %d: %d\n", ii++, ans);
		}
	}
	return 0;
}
