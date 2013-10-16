/* 
 * File:   main.cpp
 * Author: Acmer@HUST
 *
 * Created on July 12, 2010, 12:34 PM
 */

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
		int id=0, flag=0;
		multimap <int, int> mp;
		multimap <int, int> ::iterator p, q;
		for(int v, i=0;i<n;i++){
			scanf("%d", &v);
			if(flag)continue;
			nod[i].ii=v;
			mp.insert(make_pair(v, 1));
			p=mp.find(v);
			if(p==mp.begin()){
				p->second=++id;
				nod[i].st=id;
				if(id>m)flag=1;
			}
			else {
				q=p;
				p--;
				q->second=p->second;
				nod[i].st=p->second;
				mp.erase(p);
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
