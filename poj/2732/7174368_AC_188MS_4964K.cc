#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[1002], *vert[1002];

char str[12];
int n, m, deca[1001][1001], d, in[1002], out[1002];

struct node {
	string name;
	int cnt;
	bool operator<(const node & a)const {
		if (a.cnt == cnt) {
			return a.name > name;
		}
		return a.cnt < cnt;
	}
} nod[1002];

void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];
	vert[x] = p;
}

void DFS(int s) {
	for (edge *p = vert[s]; p; p = p->next) {
		DFS(p->to);
		deca[s][1]++;
		for (int i = 2; i <= n; i++) {
			deca[s][i] += deca[p->to][i - 1];
		}
	}
}

int main() {
	int nca, flag = 0;
	scanf("%d", &nca);
	for (int ii = 1; ii <= nca; ii++) {
		int id = 0, top = -1;
		map <string, int> mp;
		map <string, int> ::iterator p;
		map <int, string> gg;
		map <int, string> ::iterator q;

		scanf("%d%d", &n, &d);
		memset(in, 0, sizeof (in));
		memset(out, 0, sizeof (out));
		memset(vert, 0, sizeof (vert));
		for (int i = 0; i < n; i++) {
			scanf("%s%d", str, &m);
			int x, y;
			p = mp.find(str);
			if (p == mp.end()) {
				mp[str] = id;
				gg[id] = str;
				x = id++;
			}
			else {
				x = p->second;
			}
			for (int j = 0; j < m; j++) {
				scanf("%s", str);
				p = mp.find(str);
				if (p == mp.end()) {
					mp[str] = id;
					gg[id] = str;
					y = id++;
				}
				else {
					y = p->second;
				}
				in[y]++;
				out[x]++;
				add_edge(x, y, top);
			}
		}
		int root, tem;
		for (int i = 0; i < id; i++) {
			if (in[i] == 0) {
				root = i;
				break;
			}
		}
		n = id;
		memset(deca, 0, sizeof (deca));
		DFS(root);
		top = 0;
		for (int i = 0; i < n; i++) {
			if (deca[i][d] > 0) {
				q = gg.find(i);
				nod[top].name = q->second;
				nod[top].cnt = deca[i][d];
				top++;
			}
		}
		if (flag) {
			puts("");
		}
		else {
			flag = 1;
		}
		sort(nod, nod + top);
		printf("Tree %d:\n", ii);
		if (top <= 3) {
			for (int i = 0; i < top; i++) {
				cout << nod[i].name << " " << nod[i].cnt << endl;
			}
		}
		else {
			int cnt = nod[2].cnt, i = 0;
			for (i = 0; i < 3; i++) {
				cout << nod[i].name << " " << nod[i].cnt << endl;
			}
			while (nod[i].cnt == cnt && i < top) {
				cout << nod[i].name << " " << cnt << endl;
				i++;
			}
		}
	}
	return 0;
}