#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct deck{
	int id;
	deck *next;
}dec[100010], *head, *tail;

int n, k, p;

void solve(){
	head=&dec[0];
	for(int i=0;i<k;i++){
		dec[i].id=i+1;
		dec[i].next=&dec[i+1];
	}
	dec[k-1].next=NULL;
	tail=&dec[k-1];

	vector <int> ans;
	for(int x=1, i=0;i<k;i++){
		//printf("%d\n", head->id);
		if(x==0){
			ans.push_back(head->id);
		}
		head=head->next;
		if(!head)break;
		
		int tem=p;
		while(tem--){
			tail->next=head;
			tail=tail->next;
			head=head->next;
		}
		tail->next=NULL;
		x=(x+1)%n;
	}

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
