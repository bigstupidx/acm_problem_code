#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	double a, b, c;
	while (scanf("%lf%lf%lf", &a, &b, &c), a || b || c) {
		bool aa = false;
		bool bb = false;
		bool cc = false;
		if (a <= 4.5 && b >= 150 && c >= 200)
			aa = true;
		if (a <= 6.0 && b >= 300 && c >= 500)
			bb = true;
		if (a <= 5.0 && b >= 200 && c >= 300)
			cc = true;

		if (aa)
			printf("Wide Receiver");
		if (bb) {
			if (aa) {
				printf(" Lineman");
			} else {
				printf("Lineman");
			}
		}
		if (cc) {
			if (aa || bb) {
				printf(" Quarterback");
			} else {
				printf("Quarterback");
			}
		}
		if (!aa && !bb && !cc) {
			puts("No positions");
		} else {
			puts("");
		}
	}
	return 0;
}
