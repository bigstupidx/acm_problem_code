#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

char str[22], tem[3];
int n, my[22], gg[22][22], deg[22], inRoom[22], flag[22];

struct node{
	int ii;
	string a, b;
	bool operator <(const node &c)const{
		return c.a > a;
	}
}nod[22];

int main() {
	scanf("%d", &n);
	map <string, int> name, id, msg;
	map <string, int> ::iterator p;

	map <int, string> xx, yy;
	map <int, string> ::iterator q;
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		id[str] = i;
		yy.insert(make_pair(i, str));
	}
	int ppl, cnt1 = 0, cnt2 = 0, top = 0, cnt = 0;
	memset(my, -1, sizeof (my));
	while (scanf("%s", tem), tem[0] != 'Q') {
		scanf("%s", str);
		if (tem[0] == 'E') {
			p = name.find(str);
			if (p == name.end()) {
				name[str] = top;
				xx.insert(make_pair(top,str));
				ppl = top;
				cnt2++;
				top++;
				cnt++;
			}
			else {
				ppl = p->second;
			}
			inRoom[ppl] = 1;
		}
		else if (tem[0] == 'L') {
			p = name.find(str);
			if (p != name.end()) {
				inRoom[p->second] = 0;
				cnt--;
			}
		}
		else {
			p = msg.find(str);
			ppl=id.find(str)->second;
			if (p == msg.end()) {
				msg[str]=1;
				for (int i = 0; i < top; i++) {
					if (flag[i] != 1 && inRoom[i]) {
						gg[ppl][i] = 1;
					}
				}
				if (++cnt1 == cnt2) {
					for (int i = 0; i < top; i++) {
						flag[i] = 1;
					}
				}

			}
			else {
				for(int i=0;i<top;i++){
					if(!inRoom[i]){
						gg[ppl][i]=0;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				deg[i] = 0;
				for (int j = 0; j < n; j++) {
					if (gg[i][j]) {
						deg[i]++;
					}
				}
			}
			queue<int>Q;
			for (int i = 0; i < n; i++) {
				if (deg[i] == 1) {
					Q.push(i);
				}
			}
			while (!Q.empty()) {
				int k, i = Q.front();
				Q.pop();
				for (int j = 0; j < n; j++) {
					if (gg[i][j]) {
						k = j;
						break;
					}
				}
				my[k]=i;
				gg[i][k] = 0;
				for (int j = 0; j < n; j++) {
					if (gg[j][k]) {
						gg[j][k] = 0;
						if (--deg[j] == 1) {
							Q.push(j);
						}
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		nod[i].ii=i;
		nod[i].a=xx.find(i)->second;
		if(my[i]!=-1){
			nod[i].b=yy.find(my[i])->second;
		}
	}
	sort(nod, nod+n);
	for(int i=0;i<n;i++){
		cout<<nod[i].a<<":";
		if(my[nod[i].ii]==-1){
			puts("???");
		}
		else {
			cout<<nod[i].b<<endl;
		}
	}
	return 0;
}
