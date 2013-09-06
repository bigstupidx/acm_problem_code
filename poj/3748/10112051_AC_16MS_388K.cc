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
	int num, x, y;
	while (scanf("%x,%d,%d", &num, &x, &y) != EOF) {
		num |= 1 << y;
		num |= 1 << (y - 1);
		num &= ~(1 << x);
		num &= ~(1 << (y - 2));
		printf("%x\n", num);
	}
	return 0;
}
