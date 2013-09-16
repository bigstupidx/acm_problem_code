#include <cstdio>
#include <cstring>

using namespace std;

char str[1000010];

int main() {

	while (scanf("%s", str), strcmp(str, "0") != 0) {
		int len = strlen(str), now = 0, cnt = 0, temp;
		for (int i = 0; i < len; i++) {
			cnt += str[i] - '0';
		}
		temp = cnt;
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
