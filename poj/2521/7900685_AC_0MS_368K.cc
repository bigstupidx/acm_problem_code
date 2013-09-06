#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int a, b, c, d;
	while (scanf("%d%d%d%d", &a, &b, &c, &d), a || b || c || d) {
		printf("%d\n", a - b + c);
	}
	return 0;
}
