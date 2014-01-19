#include <cstdio>
#include <cstring>

using namespace std;

int year, nn;

bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	return false;
}

void solve() {
	while (nn > 0) {
		if (isLeapYear(year)) {
			--nn;
			if (nn == 0)
				break;
		}
		++year;
	}
	printf("%d\n", year);
}

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		scanf("%d%d", &year, &nn);
		solve();
	}
	return 0;
}
