#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;

int main(){
	while(scanf("%d", &n)!=EOF){
		map<int, vector<int> >mp;
		map<int, vector<int> >::iterator p;
		
		for(int i = 0, temp;i<n;i++){
			scanf("%d", &temp);
			p = mp.find(temp);
			if(p!=mp.end()){
				p->second.push_back(i);
			}else{
				vector<int> xx;
				xx.push_back(i);
				mp.insert(make_pair(temp, xx));
			}
		}
		map<int, int> ans;
		map<int, int> ::iterator q;
		
		for(p = mp.begin();p!=mp.end();p++){
			vector<int> value = p->second;
			
			bool flag = true;
			int xx = 0;
			
//			printf("\n %d\n", p->first);
			for(int i = 0, m = value.size();i<m;i++){
//				printf("%d   ", value[i]);
				if(i==0)continue;
				if(i==1)xx = value[1] - value[0];
				else if(xx!=value[i]-value[i-1]){
					 flag = false;
					 break;
				}
			}
//			puts("");
			
			if(flag){
				ans.insert(make_pair(p->first, xx));
			}
		}
		
		printf("%d\n", ans.size());
		for(q = ans.begin();q!=ans.end();q++){
			printf("%d %d\n", q->first, q->second);
		}
	}
	return 0;
}
