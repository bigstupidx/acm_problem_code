#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	double x;
	while (scanf("%lf", &x) != EOF) {
		printf("%.2lf\n", x >= 0 ? x : -x);
	}
	return 0;
}
