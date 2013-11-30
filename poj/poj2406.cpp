#include <cstdio>
#include <cstring>

using namespace std;

char str[1000002];

bool check(int len, int total) {
	int ll = total/len;
	for (int i = 0; i < total; i += ll) {
		for (int j = 0; j < ll; j++) {
			if (str[i + j] != str[j])
				return false;
		}
	}
	return true;
}

int main() {
	while (scanf("%s", str) != EOF) {
		if (strcmp(str, ".") == 0)
			break;

		int len = strlen(str);
		for (int i = len; i > 0; i--) {
			if (len % i == 0 && check(i, len)) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
