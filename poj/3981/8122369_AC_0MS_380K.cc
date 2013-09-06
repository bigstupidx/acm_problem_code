#include <cstdio>
#include <cstring>

using namespace std;

char str[1004];

int main() {
	while (gets(str)) {
		int len = strlen(str);
		for (int i = 0; i < len;) {
			if (i + 2 < len && str[i] == 'y' && str[i + 1] == 'o' && str[i + 2]
					== 'u') {
				printf("we");
				i += 3;
			} else {
				putchar(str[i]);
				++i;
			}
		}
		puts("");
	}
	return 0;
}
