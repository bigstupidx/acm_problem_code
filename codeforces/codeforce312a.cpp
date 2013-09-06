#include <cstdio>
#include <cstring>

using namespace std;

char str[110];
char result[3][30] = { "Freda's", "Rainbow's", "OMG>.< I don't know!" };

char* bb = "miao.", *aa = "lala.";

int check() {
	int len = strlen(str);
	if (len < 5)
		return 2;
	bool flag1 = true, flag2 = true;
	for (int i = 0; i < 5; i++) {
		if (str[i] != bb[i]) {
			flag2 = false;
		}
		if (str[len - i - 1] != aa[4 - i]) {
			flag1 = false;
		}
	}
	if (flag1 && flag2 || !flag1 && !flag2)
		return 2;
	if (flag1)
		return 0;
	return 1;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		getchar();
		for (int i = 0; i < n; i++) {
			gets(str);
			printf("%s\n", result[check()]);
		}
	}
	return 0;
}
