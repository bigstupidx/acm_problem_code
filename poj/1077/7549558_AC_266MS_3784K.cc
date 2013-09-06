#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 500010

using namespace std;

struct Qnode{
	char arr[10];
	int hh;
}now, next;

char path[maxn], ch, str[10], ans[maxn];
int fic[9]={0, 1, 2, 6, 24, 120, 720, 5040, 40320};
int arr[9], pre[maxn];
bool hash[maxn];

bool check(){
	int cnt=0;
	for(int i=0;i<8;i++){
		for(int j=i+1;j<8;j++){
			if(arr[j]>arr[i]){
				cnt++;
			}
		}
	}
	return cnt%2==0;
}

int Hash(char arr[]){
	int x[10], ans=0;
	memset(x, 0, sizeof(x));
	for(int i=0;i<8;i++){
		for(int j=i+1;j<8;j++){
			if(arr[i]<arr[j]){
				++x[j];
			}
		}
	}
	for(int i=0;i<8;i++){
		ans+=x[i]*fic[i];
	}
	ans+=('8'-arr[8])*fic[8];
	return ans;
}

void solve(){
	queue <Qnode> Q;
	for(int i=0;i<9;i++){
		now.arr[i]=arr[i]+'0';
	}
	int hh = Hash(now.arr);
	hash[hh]=1;
	now.hh = hh;
	Q.push(now);
	while(!Q.empty()){
		now=Q.front();Q.pop();
		if(strcmp(now.arr, "123456788")==0){
			return ;
		}
		//printf("%s\n", now.arr);
		//system("pause");
		int aa = now.hh;
		int temp = now.arr[8]-'0';
		strcpy(next.arr, now.arr);
		if(temp%3!=0){
			--next.arr[8];
			hh = Hash(next.arr);
			if(!hash[hh]){
				hash[hh]=1;
				path[hh] = 'l';
				pre[hh] = aa;
				next.hh = hh;
				Q.push(next);
			}
			++next.arr[8];
		}
		if(temp%3!=2){
			++next.arr[8];
			hh = Hash(next.arr);
			if(!hash[hh]){
				hash[hh]=1;
				path[hh] = 'r';
				pre[hh] = aa;
				next.hh = hh;
				Q.push(next);
			}
			--next.arr[8];
		}
		if(temp>2){
			next.arr[8]-=3;
			ch = next.arr[temp-3];
			next.arr[temp - 3] = next.arr[temp - 2];
			next.arr[temp - 2] = next.arr[temp - 1];
			next.arr[temp - 1] = ch;
			hh = Hash(next.arr);
			if(!hash[hh]){
				hash[hh] = 1;
				path[hh] = 'u';
				pre[hh] = aa;
				next.hh = hh;
				Q.push(next);
			}
		}
		if(temp<6){
			strcpy(next.arr, now.arr);
			next.arr[8]+=3;
			ch = next.arr[temp + 2];
			next.arr[temp + 2] = next.arr[temp + 1];
			next.arr[temp + 1] = next.arr[temp];
			next.arr[temp] = ch;
			hh = Hash(next.arr);
			if(!hash[hh]){
				hash[hh] = 1;
				path[hh] = 'd';
				pre[hh] = aa;
				next.hh= hh;
				Q.push(next);
			}
		}
	}
}

int main(){
	int k=0;
	for(int i=0;i<9;i++){
		scanf("%s", str);
		if(str[0]=='x'){
			arr[8]=i;
		}
		else {
			arr[k++]=str[0]-'0';
		}
	}
	if(check()){
		memset(pre, -1, sizeof(pre));
		memset(hash, 0, sizeof(hash));
		solve();
		int hh = now.hh, top=0;
		while(pre[hh]!=-1){
			ans[top++]=path[hh];
			hh=pre[hh];
		}
		for(int i=top-1;i>=0;i--){
			printf("%c", ans[i]);
		}
		puts("");
	}
	else {
		puts("unsolvable");
	}
	//system("pause");
	return 0;
}
