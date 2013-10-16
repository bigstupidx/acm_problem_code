//============================================================================
// Name        : algorithm.cpp
// Author      : wangjunyong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int x, t, a, b, da, db;
	while (scanf("%d%d%d%d%d%d", &x, &t, &a, &b, &da, &db) != EOF) {
		bool flag = false;
		for (int i = 0; i < t && !flag; i++) {
			for (int j = 0; j < t && !flag; j++) {
				if (a - i * da + b - j * db == x) {
					flag = true;
					break;
				}
			}
		}
		for (int i = 0; i < t; i++) {
			if (a - i * da == x)
				flag = true;
			if (b - i * db == x)
				flag = true;
		}
		if (flag || x == 0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
