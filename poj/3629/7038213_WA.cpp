#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct deck{
	int id;
	deck *next;
}dec[100010], *head, *tail, *now, *q;

int n, k, p;

void solve(){
	head=&dec[0];
	tail=&dec[k-1];
	for(int i=0;i<k;i++){
		dec[i].id=i+1;
		dec[i].next=&dec[i+1];
	}
	dec[k-1].next=NULL;
	int m=k-n, x=1;
	vector <int> ans;
	for(int i=0;i<m;i++){
		//printf("%d\n", head->id);
		if(x==0){
			ans.push_back(head->id);
		}
		now=head->next;
		if(i==k-1)break;
		int tem=p;
		while(tem--){
			q=now;
			now=now->next;
		}
		tail->next=head->next;
		q->next=NULL;
		tail=q;
		head=now;
		x=(x+1)%n;
	}
	ans.push_back(tail->id);
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++){
		printf("%d\n", ans[i]);
	}
}

int main(){
	while(scanf("%d%d%d", &n, &k, &p)!=EOF){
		solve();
	}
	return 0;
}
