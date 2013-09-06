#include <cstdio>
#include <cstring>

using namespace std;

double ans, r;
int R, M, Y;

int main() {
	while (scanf("%d%d%d", &R, &M, &Y) != EOF) {
		ans = M;
		r = 1.0 + R * 1.0 / 100;
		for (int i = 0; i < Y; i++) {
			ans *= r;
		}
		printf("%d\n", (int) ans);
	}
	return 0;
}
