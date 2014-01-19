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

bool flag[40000];
int queue[40000], top;

bool is_prime(int num) {
	int x = sqrt(num);
	for (int i = 2; i <= x; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

void pre_done() {
	memset(flag, 0, sizeof(flag));
	flag[1] = false;
	top = 0;
	for (int i = 2; i <= 40000; i++) {
		if (is_prime(i)) {
			flag[i] = true;
			queue[top++] = i;
		}
	}
}

int main() {
	int num;
	pre_done();
	while (scanf("%d", &num), num != 0) {
		int count = 0;
		for (int i = 0; i < top; i++) {
			if (queue[i] > num)
				break;
			int other = num - queue[i];
			if (other < queue[i])
				break;
			if (flag[num - queue[i]]) {
				++count;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
