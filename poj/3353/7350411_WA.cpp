/*
 * File:   A.cpp
 * Author: xhSong
 * Created on 2010年8月4日, 下午2:01
 * Time Complexity :
 * Space Complexity :
 * Describe :
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

void up(char s[]) {
	for (int i = 0; s[i]; ++i) {
		if ('a' <= s[i] && s[i] <= 'z') {
			s[i] = s[i] - 'a' + 'A';
		}
	}
}

int value(char c) {
	if (c == 'I') return 1;
	if (c == 'V') return 5;
	if (c == 'X') return 10;
	if (c == 'L') return 50;
	if (c == 'C') return 100;
	if (c == 'D') return 500;
	if (c == 'M') return 1000;
	if (c == 'O') return 5000;
}

int check(char s[]) {
	int len = strlen(s);
	//V、L、D只出现一次
	for (int i = 1; i < len; ++i) {
		if ((s[i] == 'V' || s[i] == 'L' || s[i] == 'D') && s[i] == s[i - 1]) {
			return -1;
		}
	}
	//I、X、C不能连续出现3个以上
	int ci = 0, cx = 0, cc = 0;
	for (int i = 0; s[i]; ++i) {
		if (s[i] == 'I') {
			ci++;
			cx = cc = 0;
			if (ci > 3) {
				return -1;
			}
		} else if (s[i] == 'X') {
			cx++;
			ci = cc = 0;
			if (cx > 3) {
				return -1;
			}
		} else if (s[i] == 'C') {
			cc++;
			cx = cc = 0;
			if (cc > 3) {
				return -1;
			}
		} else {
			cc = cx = ci = 0;
		}
	}
	//O后面不能跟M
	for (int i = 1; i < len; ++i) {
		if (s[i - 1] == 'O' && s[i] == 'M') {
			return -1;
		}
	}
	return 0;
}

/*给你罗马数字，返回对应数字，-1表示非法*/
long long rtoi(char s[]) {
	if (check(s) == -1) {
		return -1;
	}
	int prev = 500000;
	long long x = 0;
	for (int i = 0; s[i]; ++i) {
		if (s[i] == 'O') {
			if (x <= 3) {
				return -1;
			} else {
				x *= 1000;
			}
		} else if (prev < value(s[i])) {
			/*IV = 5 - 1 = 4
				IX = 10 - 1 = 9
				XL = 50 - 10 = 40
				XC = 100 - 10 = 90
				CD = 500 - 100 = 400
			 */
			if (s[i - 1] == 'I' && s[i] == 'V') {
				x += 3;
			} else if (s[i - 1] == 'I' && s[i] == 'X') {
				x += 8;
			} else if (s[i - 1] == 'X' && s[i] == 'L') {
				x += 30;
			} else if (s[i - 1] == 'X' && s[i] == 'C') {
				x += 80;
			} else if (s[i - 1] == 'C' && s[i] == 'D') {
				x += 300;
			} else {
				return -1;
			}
		} else {
			x += value(s[i]);
		}
		prev = value(s[i]);
	}
	return x;
}

void output(int x) {
	switch (x) {
		case 1:
			printf("I");
			break;
		case 2:
			printf("II");
			break;
		case 3:
			printf("III");
			break;
		case 4:
			printf("IV");
			break;
		case 5:
			printf("V");
			break;
		case 6:
			printf("VI");
			break;
		case 7:
			printf("VII");
			break;
		case 8:
			printf("VIII");
			break;
		case 9:
			printf("IX");
			break;
		case 1000:
			printf("M");
			break;
		case 900:
			printf("CM");
			break;
		case 800:
			printf("DCCC");
			break;
		case 700:
			printf("DCC");
			break;
		case 600:
			printf("DC");
			break;
		case 500:
			printf("D");
			break;
		case 400:
			printf("CD");
			break;
		case 300:
			printf("CCC");
			break;
		case 200:
			printf("CC");
			break;
		case 100:
			printf("C");
			break;
		case 90:
			printf("XC");
			break;
		case 80:
			printf("LXXX");
			break;
		case 70:
			printf("LXX");
			break;
		case 60:
			printf("LX");
			break;
		case 50:
			printf("L");
			break;
		case 40:
			printf("XL");
			break;
		case 30:
			printf("XXX");
			break;
		case 20:
			printf("XX");
			break;
		case 10:
			printf("X");
			break;
	}
}

void itor(char s[], long long x) {
	int p[10], k = 0, i = 0;
	while (x) {
		p[k++] = x % 1000;
		x /= 1000;
	}
	if (p[k - 1] <= 3) {
		k--;
		for (int i = 0; i < p[k]; ++i) {
			output(1000);
		}
	}
	while (k) {
		k--;
		output(p[k] / 100 * 100);
		output(p[k] / 10 % 10 * 10);
		output(p[k] % 10);
		if (k) {
			printf("O");
		}
	}
}

int main(int argc, char** argv) {
	char s[1000], t[1000];
	while (scanf("%s", s) != EOF) {
		up(s);
		int i = 0, j = 0;
		while (s[i] && s[i] != '+') {
			i++;
		}
		s[i++] = '\0';
		while (s[i]) {
			t[j++] = s[i++];
		}
		t[j] = '\0';
		long long a = rtoi(s), b = rtoi(t);
		if (a == -1 || b == -1) {
			puts("INVALID");
		} else {
			itor(s, a + b);
			printf("=%lld\n", a + b);
		}
	}
	return 0;
}