//============================================================================
// Name        : algorithm.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
	int nca;
	scanf("%d", &nca);
	for (int ii = 1; ii <= nca; ii++) {
		printf("Scenario #%d:\n", ii);
		long long a, b;
		scanf("%I64d%I64d", &a, &b);
		printf("%I64d\n\n", (a + b) * (b - a + 1) / 2);
	}
	return 0;
}
