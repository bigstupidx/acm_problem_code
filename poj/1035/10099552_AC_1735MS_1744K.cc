//============================================================================
// Name        : algorithm.cpp
// Author      : wangjunyong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

char str[20], temp[20];
map<string, int> dic;

void solve() {
	if (dic.find(str) != dic.end()) {
		printf("%s is correct\n", str);
		return;
	}
	map<int, string> ans;
	map<int, string>::iterator p;
	map<string, int>::iterator q;
	printf("%s:", str);
	int len = strlen(str);
	//delete
	for (int i = 0; i < len; i++) {
		int k = 0;
		for (int j = 0; j < len; j++) {
			if (j == i)
				continue;
			temp[k++] = str[j];
		}
		temp[k] = 0;
		q = dic.find(temp);
		if (q != dic.end()) {
			ans.insert(make_pair(q->second, temp));
		}

		strcpy(temp, str);
		for (int j = 0; j < 26; j++) {
			temp[i] = 'a' + j;
			q = dic.find(temp);
			if (q != dic.end()) {
				ans.insert(make_pair(q->second, temp));
			}
		}
	}
	//
	++len;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < i; j++) {
			temp[j] = str[j];
		}
		for (int j = 0; j < 26; j++) {
			temp[i] = 'a' + j;
			for (int xx = i + 1; xx < len; xx++) {
				temp[xx] = str[xx - 1];
			}
			temp[len] = 0;
			q = dic.find(temp);
			if (q != dic.end()) {
				ans.insert(make_pair(q->second, temp));
			}
		}
	}

	for (p = ans.begin(); p != ans.end(); p++) {
//		printf(" %s", p->second);
		cout << " " << p->second;
	}
	puts("");
	return;
}

int main() {
	int nca = 0;
	while (scanf("%s", str), strcmp(str, "#") != 0) {
		dic.insert(make_pair(str, nca));
		++nca;
	}
	while (scanf("%s", str), strcmp(str, "#") != 0) {
		solve();
	}
	return 0;
}
