#include <cstdio>
#include <cstring>

struct node {
	int ii;
	int v;
} nod[10010];
char str[1000010], tem[1000010];

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
	//printf("%d %s %d\n", v1, str, v2);
	v2=nod[v2].v;
	int xflag=0;
	while (k > 0) {
		k--;
		if (str[k] == 'f') {
			v2 = get_next(nod[v2].ii);
		} else if (str[k] == 'b') {
			v2 = get_pre(nod[v2].ii);
		} else if (str[k] == 'k') {
			printf("%d ", v2);
			xflag=1;
		} else if (str[k] == '<') {
			nod[v1].v = v2;
		} else {
			xflag=1;
			printf("%c ", nod[v2].v == v1 ? '=' : '#');
		}
	}
	if(xflag)puts("");
}

int main() {
	//freopen("out.txt", "w", stdout);
	for (int i = 0; i < 10001; i++) {
		nod[i].ii = i;
		nod[i].v = 0;
	}
	nod[1].v = 1;
	nod[2].v = 2;
	nod[3].v = 3;
	while (gets(tem)) {
		solve();
	}
	return 0;
}
