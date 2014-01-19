#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
	char name[102];
	int a, b, c, sum;
} nod[22];

bool cmp1(const node &x, const node &y) {
	if (x.a == y.a) {
		if (x.b == y.b)return x.c > y.c;
		return x.b > y.b;
	}
	return x.a > y.a;
}

bool cmp2(const node &x, const node &y) {
	if (x.a == y.a) {
		if (x.c == y.c)
			return x.b > y.b;
		return x.c > y.c;
	}
	return x.a > y.a;
}

bool cmp3(const node &x, const node &y) {
	if (x.b == y.b) {
		if (x.a == y.a)return x.c > y.c;
		return x.a > y.a;
	}
	return x.b > y.b;
}

bool cmp4(const node &x, const node &y) {
	if (x.b == y.b) {
		if (x.c == y.c)return x.a > y.a;
		return x.c > y.c;
	}
	return x.b > y.b;
}

bool cmp5(const node &x, const node &y) {
	if (x.c == y.c) {
		if (x.a == y.a)return x.b > y.b;
		return x.a > y.a;
	}
	return x.c > y.c;
}

bool cmp6(const node &x, const node &y) {
	if (x.c == y.c) {
		if (x.b == y.b)return x.a > y.a;
		return x.b > y.b;
	}
	return x.c > y.c;
}

bool cmp7(const node &x, const node &y) {
	return x.sum > y.sum;
}

int main() {
	int n;
	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; i++) {
			scanf("%s", nod[i].name);
			scanf("%d%d%d", &nod[i].a, &nod[i].b, &nod[i].c);
			nod[i].sum = nod[i].a + nod[i].b + nod[i].c;
		}
		int xflag = 0;
		sort(nod, nod + n, cmp1);
		if (strcmp(nod[0].name, "Canada") == 0) {
			if (nod[0].a > nod[1].a || nod[0].b > nod[1].b || nod[0].c > nod[1].c)
				xflag = 1;
		}
		sort(nod, nod + n, cmp2);
		if (strcmp(nod[0].name, "Canada") == 0) {
			if (nod[0].a > nod[1].a || nod[0].c > nod[1].c || nod[0].b > nod[1].b)
				xflag = 1;
		}
		sort(nod, nod + n, cmp3);
		if (strcmp(nod[0].name, "Canada") == 0) {
			if (nod[0].b > nod[1].b || nod[0].a > nod[1].a || nod[0].c > nod[1].c)
				xflag = 1;
		}
		sort(nod, nod + n, cmp4);
		if (strcmp(nod[0].name, "Canada") == 0) {
			if (nod[0].b > nod[1].b || nod[0].c > nod[1].c || nod[0].a > nod[1].a)
				xflag = 1;
		}
		sort(nod, nod + n, cmp5);
		if (strcmp(nod[0].name, "Canada") == 0) {
			if (nod[0].c > nod[1].c || nod[0].a > nod[1].a || nod[0].b > nod[1].b)
				xflag = 1;
		}
		sort(nod, nod + n, cmp6);
		if (strcmp(nod[0].name, "Canada") == 0) {
			if (nod[0].c > nod[1].c || nod[0].b > nod[1].b || nod[0].a > nod[1].a)
				xflag = 1;
		}
		sort(nod, nod + n, cmp7);
		if (strcmp(nod[0].name, "Canada") == 0) {
			if (nod[0].sum > nod[1].sum)
				xflag = 1;
		}
		if (xflag)puts("Canada wins!");
		else puts("Canada cannot win.");
	}
	return 0;
}
