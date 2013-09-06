#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Qnode{
	char arr[9];
	int hh;
}now, next;

char path[500010], ch, ans[500010];
int arr[10], pre[500010], fic[9]={0, 1, 2, 6, 24, 120, 720, 5040, 40320};
bool hash[500010];

bool check(){
	int cnt=0;
	for(int i=0;i<8;i++){
		for(int j=i+1;j<8;j++){
			if(arr[j]>arr[i])cnt++;
		}
	}
	return cnt%2==0;
}

int Hash(char *arr){
	int x[10], ans=0;
	memset(x, 0, sizeof(x));
	for(int i=0;i<8;i++){
		for(int j=i+1;j<8;j++){
			if(arr[j]>arr[i]){
				x[j]++;
			}
		}
	}
	for(int i=1;i<8;i++){
		ans+=x[i]*fic[i];
	}
	ans+=('9'-arr[8])*fic[8];
	return ans;
}

void solve(){
	queue <Qnode> Q;
	for(int i=0;i<9;i++){
		now.arr[i]=arr[i]+'0';
	}
	int hh = Hash(now.arr);
	hash[hh] = true;
	now.hh = hh;
	Q.push(now);
	while(!Q.empty()){
		now=Q.front();Q.pop();
		if(strcmp(now.arr, "123456788")==0){
			return ;
		}
		//puts(now.arr);
		strcpy(next.arr, now.arr);
		int aa = now.hh;
		int temp = now.arr[8]-'0';
		if(temp % 3 != 0){
			--next.arr[8];
			hh = Hash(next.arr);
			if(!hash[hh]){
				hash[hh]=true;
				pre[hh]=aa;
				path[hh]='l';
				next.hh = hh;
				Q.push(next);
			}
			++next.arr[8];
		}
		if(temp % 3 != 2){
			++next.arr[8];
			hh = Hash(next.arr);
			if(!hash[hh]){
				hash[hh] = true;
				pre[hh] = aa;
				path[hh] = 'r';
				next.hh = hh;
				Q.push(next);
			}
			--next.arr[8];
		}
		if(temp >2){
			next.arr[8]-=3;
			ch = next.arr[temp-3];
			next.arr[temp-3] = next.arr[temp-2];
			next.arr[temp-2] = next.arr[temp-1];
			next.arr[temp-1] = ch;
			hh = Hash(next.arr);
			if(!hash[hh]){
				hash[hh]=true;
				pre[hh]=aa;
				path[hh] = 'u';
				next.hh= hh;
				Q.push(next);
			}
		}
		if(temp < 6){
			strcpy(next.arr, now.arr);
			next.arr[8] += 3;
			ch = next.arr[temp+2];
			next.arr[temp+2] = next.arr[temp+1];
			next.arr[temp+1] = next.arr[temp];
			next.arr[temp] = ch;
			hh = Hash(next.arr);
			if(!hash[hh]){
				hash[hh]=true;
				pre[hh]=aa;
				path[hh]='d';
				next.hh=hh;
				Q.push(next);
			}
		}
	}
}

int main(){
	int k=-1;
	for(int i=0;i<9;i++){
		scanf("%s", path);
		if(path[0]=='x') arr[8]=i;
		else arr[++k]=path[0]-'0';
	}
	if(check()){
		memset(hash, 0, sizeof(hash));
		memset(pre, -1, sizeof(pre));
		solve();
		int hh = now.hh, top=0;
		while(hh!=-1){
			ans[top++] = path[hh];
			hh=pre[hh];
		}
		for(int i=top-2;i>=0;i--){
			printf("%c", ans[i]);
		}
		puts("");
	}
	else puts("unsolvable");
	system("pause");
	return 0;
}

