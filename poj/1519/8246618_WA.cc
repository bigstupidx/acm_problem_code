#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	long input, temp;
	while (scanf("%ld", &input), input) {
		temp = input;
		long cnt = 0;
		do {
			cnt = 0;
			while (temp) {
				cnt += temp % 10;
				temp /= 10;
			}
			temp = cnt;
		} while (cnt >= 10);
		printf("%d\n", cnt);
	}
	return 0;
}
