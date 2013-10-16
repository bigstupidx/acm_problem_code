#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int n, w, hh, arr[2][12];
char str[12][12], gg[12][12];

void solve(){
	int h, m=0, pre;
	vector <int> ans;
	for(int i=0;i<n;i++){
		scanf("%d", &h);
		for(int j=0;j<h;j++){
			scanf("%s", str[j]);
		}
		if(m == 0){
			m += h;
		}
		else {
			int mini = 1000000;
			for(int j=0;j<w;j++){
				int cnt1=0, cnt2=0, k=h-1;
				while(k>=0&&str[k][j]=='.')k--, cnt1++;
				k=0;
				while(k<pre&&gg[k][j]=='.')k++, cnt2++;
				if(mini>cnt1+cnt2){
					mini=cnt1+cnt2;
				}
				//printf("%d %d  \n", cnt1, cnt2);
			}
			mini = h-mini;
			if(m+mini>hh){
				ans.push_back(m);
				m=h;
			}
			else {
				m+=mini;
			}
		}
		//printf("%d %d %d\n", m, h, pre);
		pre = h;
		for(int j=0;j<h;j++){
			strcpy(gg[j], str[j]);
		}
	}
	ans.push_back(m);
	for(int i=0;i<ans.size();i++){
		printf("%d ", ans[i]);
	}
	puts("");
}

int main(){
	while(scanf("%d%d%d", &n, &w, &hh), n||w||hh){
		solve();
	}
	return 0;
}
