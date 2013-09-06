#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int main(){
	map <pair<int,int>,int> arc, desc;
	map <pair<int,int>,int> ::iterator p;
	int x, y, z;
	while(scanf("%d", &x), x){
		if(x==2){
			if(desc.size()==0){
				puts("0");
			}
			else {
				p=desc.begin();
				z=p->first.first;
				y=p->first.second;
				printf("%d\n", y);
				desc.erase(p);
				p=arc.find(make_pair(-z, y));
				arc.erase(p);
			}
		}
		else if(x==3){
			if(arc.size()==0){
				puts("0");
			}
			else {
				p=arc.begin();
				y=p->first.first;
				z=p->first.second;
				printf("%d\n", z);
				arc.erase(p);
				p=desc.find(make_pair(-y, z));
				desc.erase(p);
			}
		}
		else {
			scanf("%d%d", &y, &z);
			arc.insert(make_pair(make_pair(z, y),1));
			desc.insert(make_pair(make_pair(-z, y),1));
		}
	}
	return 0;
}
