#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int n;
	while (scanf("%d", &n), n != -1) {
		int pre = 0, next, total = 0;
		for (int v, i = 0; i < n; i++) {
			scanf("%d%d", &v, &next);
			total += v * (next - pre);
			pre = next;
		}
		printf("%d miles\n", total);
	}
	return 0;
}
