#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

char str[202];
int n;

bool getNextStr() {
	int pos = -1, nex = -1;
	for (int i = n - 1; i > 0; i--) {
		if (str[i] > str[i - 1]) {
			pos = i - 1;
			break;
		}
	}
	if (pos == -1)
		return false;
	for (int i = n - 1; i > 0; i--) {
		if (str[i] > str[pos]) {
			nex = i;
			break;
		}
	}
	char ch = str[pos];
	str[pos] = str[nex];
	str[nex] = ch;
	for (int i = n - 1; i > pos + (n - pos - 1) / 2; i--) {
		ch = str[i];
		str[i] = str[pos + n - i];
		str[pos + n - i] = ch;
	}
	return true;
}

void solve() {
	do {
		printf("%s\n", str);
	} while (getNextStr());
}

int main() {
	while (scanf("%s", str) != EOF) {
		n = strlen(str);
		sort(str, str + n);
		solve();
	}
	return 0;
}
