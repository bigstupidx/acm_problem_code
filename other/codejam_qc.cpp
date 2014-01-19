#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int arr[10], cc[10], nn, mm;
bool mark[20000010];
set<int> st;

int gao(int n){
	int j = 0;
	while(n){
		arr[j++] = n%10;
		n/=10;
	}
	st.clear();
	
	for(int k = 0;k<j;k++){
		int sum = 0;
		for(int i = j-1;i>=0;i--){
			sum*=10;
			if(i-k<0)sum+=arr[i-k+j];
			else sum+=arr[i-k];
		}
		if(sum>mm || sum<nn)continue;
		mark[sum] = true;
		st.insert(sum);
	}
	return st.size();
}

__int64 solve(){
	__int64 ans = 0;
	scanf("%d%d", &nn, &mm);
	memset(mark, false, sizeof(mark));
	for(int i = nn;i<=mm;i++){
		if(!mark[i])
		ans+=cc[gao(i)];
	}
	return ans;
}

void pre_done(){
	cc[0] = 0;
	cc[1] = 0;
	cc[2] = 1;
	cc[3] = 3;
	cc[4] = 6;
	cc[5] = 10;
	cc[6] = 15;
	cc[7] = 21;
	cc[8] = 28;
	cc[9] = 36;
}
	
int main(){
	freopen("C-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int nca;
	scanf("%d", &nca);
	pre_done();
	for(int ii = 1;ii<=nca;ii++){
		printf("Case #%d: %lld\n", ii, solve());
	}
	return 0;
}
