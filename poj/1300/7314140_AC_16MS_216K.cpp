#include <cstdio>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>

using namespace std;

char str[200];
int n, deg[22];

int main() {
	while (scanf("%s", str), strcmp(str, "ENDOFINPUT") != 0) {
		int s, cnt = 0;
		scanf("%d%d", &s, &n);
		getchar();
		memset(deg, 0, sizeof (deg));
		for (int v, i = 0; i < n; i++) {
			gets(str);
			string st(str);
			istringstream ccin(st);
			while (ccin >> v) {
				deg[i]++, deg[v]++;
				cnt++;
			}
		}
		gets(str);
		int xflag = 0;
		for (int i = 1; i < n; i++) {
			if (i != s && deg[i] % 2) {
				xflag = 1;
			}
		}
		if (xflag)puts("NO");
		else if (s != 0 && (deg[s] % 2 == 0 || deg[0] % 2 == 0))
			puts("NO");
		else if (s == 0 && deg[0] % 2)
			puts("NO");
		else {
			printf("%s %d\n", "YES", cnt);
		}
	}
	return 0;
}

