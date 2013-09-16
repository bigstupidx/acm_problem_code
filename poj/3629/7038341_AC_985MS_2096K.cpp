#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, p, k;

int main(){
	queue<int>Q;
	scanf("%d%d%d", &n, &k, &p);
	for(int i=0;i<k;i++){
		Q.push(i+1);
	}
	int x=1;
	vector<int>ans;
	while(!Q.empty()){
		int y=Q.front();Q.pop();
		//printf("%d\n", y);
		//system("pause");
		if(!x){
			ans.push_back(y);
		}
		if(!Q.empty()){
			int tem=p;
			while(tem--){
				y=Q.front();Q.pop();
				Q.push(y);
			}
		}
		x=(x+1)%n;
	}
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++){
		printf("%d\n", ans[i]);
	}
	system("pause");
	return 0;
}
