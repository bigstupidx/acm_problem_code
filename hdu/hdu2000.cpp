#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[5];

int main() {
	while (scanf("%s", str) != EOF) {
		sort(str, str + 3);
		printf("%c %c %c\n", str[0], str[1], str[2]);
	}
	return 0;
}
