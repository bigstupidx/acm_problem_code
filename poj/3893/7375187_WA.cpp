#include <cstdio>
#include <cstring>

char str[1000010], tem[1000010];
int arr[10010];

int get_pre(int x) {
	return x - 2;
}

int get_next(int x) {
	if (x % 2)return x + 1;
	return x + 3;
}

bool is_num(char ch) {
	if (ch <= '9' && ch >= '0')return true;
	return false;
}

void solve() {
	int v1 = 0, v2 = 0, i = 0, k = 0;
	while (!is_num(tem[i]))i++;
	while (is_num(tem[i])) {
		v1 *= 10;
		v1 += tem[i] - '0';
		i++;
	}
	while (!is_num(tem[i])) {
		if (tem[i] != ' ') {
			str[k++] = tem[i];
		}
		i++;
	}
	while (is_num(tem[i])) {
		v2 *= 10;
		v2 += tem[i] - '0';
		i++;
	}
	str[k] = 0;
	printf("%d %s %d\n", v1, str, v2);
	while (k > 0) {
		k--;
		if (str[k] == 'f') {
			v2 = get_next(v2);
		} else if (str[k] == 'b') {
			v2 = get_pre(v2);
		} else if (str[k] == 'k') {
			printf("%d ", v2);
		} else if (str[k] == '<') {
			arr[v1]=v2;
		} else {
			printf("%c ", arr[v2] == v1 ? '=' : '#');
		}
	}
	puts("");
}

int main() {
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	while (gets(tem)) {
		solve();
	}
	return 0;
}
