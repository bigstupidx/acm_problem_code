#include <cstdio>
#include <cstring>

int arr[1010], n, k;

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &k) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < k; i++) {
			int ii = 0, maxi = arr[0];
			for (int j = 1; j < n; j++) {
				if (arr[j] > maxi) {
					ii = j;
					maxi = arr[j];
				}
			}
			printf("%d\n", ii + 1);
			if (n != 1) {
				int y = maxi / (n - 1);
				int x = maxi % (n - 1);
				for (int j = 0; j < n; j++) {
					if (j == ii)continue;
					if (x) {
						arr[j]++;
						x--;
					}
					arr[j] += y;
					//printf("%d ", arr[j]);
				}
				//puts("");
				arr[ii] = 0;
			}
		}
	}
	return 0;
}
