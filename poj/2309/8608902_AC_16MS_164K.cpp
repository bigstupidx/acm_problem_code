#include <cstdio>
#include <cstring>

using namespace std;

int n, arr[40], top;

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		scanf("%d", &n);
		top = 0;
		int k = -1;
		while (n) {
			arr[top] = n % 2;
			if (arr[top] == 1 && k == -1) {
				k = top;
			}
			n >>= 1;
			++top;
		}
		int mini = 0, maxi = 0;
		arr[k] = 0;
		arr[0] = 1;
		for (int fic = 1, i = 0; i < top; i++) {
			mini += arr[i] * fic;
			fic <<= 1;
		}
		arr[k] = 1;
		for (int i = 0; i < k; i++) {
			arr[i] = 1;
		}
		for (int fic = 1, i = 0; i < top; i++) {
			maxi += arr[i] * fic;
			fic <<= 1;
		}
		printf("%d %d\n", mini, maxi);
	}
	return 0;
}
