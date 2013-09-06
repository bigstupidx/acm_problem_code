#include <cstdio>
#include <cstring>

using namespace std;

int n, m, fic[22], arr[22];

void pre_done() {
	fic[0] = 1;
	for (int i = 1; i < 22; i++) {
		fic[i] = fic[i - 1]*2;
	}
	return;
}

int main() {
	pre_done();
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
		}
		int mini = 1000000000;
		for (int i = 0; i < fic[n]; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					sum += arr[j];
				}
			}
			if (sum >= m && sum - m < mini)mini = sum - m;
		}
		printf("%d\n", mini);
	}
	return 0;
}
