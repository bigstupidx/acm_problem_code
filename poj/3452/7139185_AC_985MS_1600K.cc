#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
struct node{
	int ii;
	int st;
	bool operator <(const node &a)const{
		return a.ii > ii;
	}
}nod[200010];

int main(){
	while(scanf("%d%d", &n, &m), n||m){
		map<int, int> mp;
		map<int, int> ::iterator p, q;
		int flag=0, id=0;
		for(int i=0;i<n;i++){
			int u;
			scanf("%d", &u);
			if(flag)continue;
			nod[i].ii=u;
			p=mp.find(u);
			if(p!=mp.end()){
				nod[i].st=p->second;
			}
			else {
				mp.insert(make_pair(u, 1));
				p=mp.find(u);
				if(p==mp.begin()){
					if(++id>m){
						flag=1;
					}
					p->second=id;
					nod[i].st=id;
				}
				else {
					q=p;
					p--;
					q->second=p->second;
					nod[i].st=p->second;
					mp.erase(p);
				}
			}
		}
		if(flag){
			puts("Transportation failed");
		}
		else {
			for(int i=0;i<n;i++){
				printf("%d ", nod[i].st);
			}
			puts("");
			sort(nod, nod+n);
			for(int i=0;i<n;i++){
				printf("%d ", nod[i].st);
			}
			puts("");
		}
	}
	return 0;
}
