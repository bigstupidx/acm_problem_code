#include <cstdio>
#include <cstring>

using namespace std;

struct node {
    int ii;
    int v;
} nod[10010];

char str[10010], tem[10010];

int get_pre(int x) {
    return x - 2;
}

int get_next(int x) {
    if (x % 2)return x + 1;
    return x + 3;
}

bool is_numb(char ch) {
    if (ch >= '0' && ch <= '9')return true;
    return false;
}

void solve() {
    int i = 0, v1 = 0, v2 = 0, k = 0;
    while (!is_numb(tem[i]))i++;
    while (is_numb(tem[i])) {
	v1 *= 10;
	v1 += tem[i] - '0';
	i++;
    }
    while (!is_numb(tem[i])) {
	if (tem[i] != ' ') {
	    str[k++] = tem[i];
	}
	i++;
    }
    while (is_numb(tem[i])) {
	v2 *= 10;
	v2 += tem[i] - '0';
	i++;
    }
    v2 = nod[v2].v;
    bool xflag = 0;
    //printf("%d %s %d\n", v1, str, v2);
    while (k > 0) {
	k--;
	//printf("%c ", str[k]);
	if (str[k] == 'f') {
	    v2 = get_next(nod[v2].ii);
	} else if (str[k] == 'b') {
	    v2 = get_pre(nod[v2].ii);
	} else if (str[k] == 'k') {
	    xflag = true;
	    printf("%d ", v2);
	} else if (str[k] == '<') {
	    nod[v1].v = v2;
	} else {
	    xflag = true;
	    printf("%c ", nod[v1].v == v2 ? '=' : '#');
	}
    }
    if (xflag)puts("");
}

int main() {
    for (int i = 0; i < 10010; i++) {
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
