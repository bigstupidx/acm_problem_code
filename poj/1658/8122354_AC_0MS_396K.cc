#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, aa[6], bb[6];

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		for (int i = 0; i < 4; i++) {
			scanf("%d", &aa[i]);
			if (i > 0) {
				bb[i] = aa[i] - aa[i - 1];
			}
		}
		if (bb[1] == bb[2] && bb[2] == bb[3]) {
			for (int i = 0; i < 4; i++) {
				printf("%d ", aa[i]);
			}
			printf("%d\n", aa[3] + bb[1]);
		} else {
			for (int i = 0; i < 4; i++) {
				printf("%d ", aa[i]);
			}
			printf("%d\n", aa[3] * (aa[1] / aa[0]));
		}
	}
	return 0;
}
