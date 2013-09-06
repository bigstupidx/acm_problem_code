#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

char str[22], tem[3];
int n, gg[22][22], inRoom[22], flag[22], oppo[22], my[22];

struct node {
	int ii;
	string b, c;
	bool operator<(const node & a)const {
		return a.b > b;
	}
} nod[22];

bool path(int s) {
	for (int i = 0; i < n; i++) {
		if (!flag[i] && gg[s][i]) {
			flag[i] = 1;
			if (oppo[i] == -1 || path(oppo[i])) {
				oppo[i] = s;
				return true;
			}
		}
	}
	return false;
}

bool max_match() {
	memset(oppo, -1, sizeof (oppo));
	for (int i = 0; i < n; i++) {
		memset(flag, 0, sizeof (flag));
		if (!path(i)) {
			return false;
		}
	}
	return true;
}

void perfect_match() {
	memset(my, -1, sizeof (my));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (gg[i][j]) {
				gg[i][j] = 0;
				if (!max_match()) {
					gg[i][j] = 1;
					my[j] = i;
					for (int k = 0; k < n; k++) {
						if (k != j && gg[i][k]) {
							gg[i][k] = 0;
						}
						if (k != i && gg[k][j]) {
							gg[k][j] = 0;
						}
					}
					break;
				}
				gg[i][j] = 1;
			}
		}
	}
}

int main() {
	while (scanf("%d", &n) != EOF) {
		map <string, int> name, mp, msg;
		map <string, int> ::iterator p;

		map <int, string> r_name, r_mp;
		map <int, string> ::iterator q;

		for (int i = 0; i < n; i++) {
			scanf("%s", str);
			name[str] = i;
			r_name.insert(make_pair(i, str));
		}
		int id = 0, k;
		memset(gg, 0, sizeof (gg));
		memset(inRoom, 0, sizeof (inRoom));
		while (scanf("%s", tem), tem[0] != 'Q') {
			scanf("%s", str);
			if (tem[0] == 'E') {
				p = mp.find(str);
				if (p == mp.end()) {
					r_mp.insert(make_pair(id, str));
					mp[str] = id;
					k = id;
					id++;
				}
				else {
					k = p->second;
				}
				inRoom[k] = 1;
			}
			else if (tem[0] == 'L') {
				p = mp.find(str);
				if (p != mp.end()) {
					inRoom[p->second] = 0;
				}
			}
			else {
				p = msg.find(str);
				k = name.find(str)->second;
				if (p == msg.end()) {
					msg[str] = 1;
					for (int i = 0; i < id; i++) {
						if (inRoom[i]) {
							gg[k][i] = 1;
						}
					}
				}
				else {
					for (int i = 0; i < id; i++) {
						if (!inRoom[i]) {
							gg[k][i] = 0;
						}
					}
				}
			}
		}
		for (p = name.begin(); p != name.end(); p++) {
			if (msg.find(p->first) == msg.end()) {
				for (int i = 0; i < n; i++) {
					gg[p->second][i] = 1;
				}
			}
		}
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", gg[i][j]);
			}
			puts("");
		}
		*/
		perfect_match();
		for (int i = 0; i < n; i++) {
			nod[i].ii = i;
			nod[i].b = r_mp.find(i)->second;
			if (my[i] != -1) {
				nod[i].c = r_name.find(my[i])->second;
			}
		}
		sort(nod, nod + n);
		for (int i = 0; i < n; i++) {
			cout << nod[i].b << ":";
			if (my[nod[i].ii] == -1) {
				puts("???");
			}
			else {
				cout << nod[i].c << endl;
			}
		}
	}
	return 0;
}
