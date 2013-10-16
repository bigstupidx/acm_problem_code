//============================================================================
// Name        : algorithm.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cstring>

using namespace std;

bool exist[30];
char left[3][30], right[3][30], result[3][30];

bool check(int i, int j) {
	for (int ii = 0; ii < 3; ii++) {
		int len = strlen(left[ii]), suma = 0, sumb = 0;
		for (int jj = 0; jj < len; jj++) {
			int aa = left[ii][jj] - 'A';
			int bb = right[ii][jj] - 'A';
			if (aa != i)
				++suma;
			else
				suma += j;
			if (bb != i)
				++sumb;
			else
				sumb += j;
		}
		if (suma < sumb && strcmp(result[ii], "down") != 0) {
			return false;
		} else if (suma == sumb && strcmp(result[ii], "even") != 0) {
			return false;
		} else if (suma > sumb && strcmp(result[ii], "up") != 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		memset(exist, 0, sizeof(exist));
		for (int i = 0; i < 3; i++) {
			scanf("%s%s%s", left[i], right[i], result[i]);
			int len = strlen(left[i]);
			for (int j = 0; j < len; j++) {
				exist[left[i][j] - 'A'] = true;
				exist[right[i][j] - 'A'] = true;
			}
		}
		bool flag = false;
		for (int i = 0; i < 20 && !flag; i++) {
			if (exist[i]) {
				for (int j = 0; j < 3; j += 2) {
					if (check(i, j)) {
						flag = true;
						if (j == 0) {
							printf("%c is the counterfeit coin and it is light. \n", i + 'A');
						} else {
							printf("%c is the counterfeit coin and it is heavy. \n", i + 'A');
						}
						break;
					}
				}
			}
		}
	}
	return 0;
}
