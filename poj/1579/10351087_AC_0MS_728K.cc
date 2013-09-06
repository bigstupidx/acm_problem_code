//============================================================================
// Name        : algorithm.cpp
// Author      : wangjunyong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int inf = 1000000000;

int arr[22][22][22];

int solve(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return solve(20, 20, 20);
	if (arr[a][b][c] != -inf)
		return arr[a][b][c];
	if (a < b && b < c) {
		return arr[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1)
				- solve(a, b - 1, c);
	} else {
		return arr[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c)
				+ solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
	}
}

int main() {
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 22; j++) {
			for (int k = 0; k < 22; k++) {
				arr[i][j][k] = -inf;
			}
		}
	}
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) != EOF) {
		if (a == -1 && b == -1 && c == -1)
			break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, solve(a, b, c));
	}
	return 0;
}
