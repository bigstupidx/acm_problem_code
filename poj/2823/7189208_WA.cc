#include <cstdio>
#include <cstring>
#define maxn 1000010

int n, len, mini[maxn], maxi[maxn], que[maxn], arr[maxn];

void get_mini(){
	int ff=0, rt=0;
	que[0]=0;
	for(int i=1;i<len;i++){
		while(rt>=0&&arr[i]<arr[que[rt]]){
			rt--;
		}
		if(rt<0||arr[i]<arr[que[rt]]){
			que[++rt]=i;
		}
	}
	int m=n-len+1;
	mini[0]=arr[que[0]];
	for(int i=1;i<m;i++){
		while(que[ff]<i){
			ff++;
		}
		while(rt>=ff&&arr[i+len-1]<arr[que[rt]]){
			rt--;
		}
		if(rt<ff||arr[i+len-1]<arr[que[rt]]){
			que[++rt]=i+len-1;
		}
		mini[i]=arr[que[ff]];
	}
}

void get_maxi(){
	int ff=0, rt=0;
	que[0]=0;
	for(int i=1;i<len;i++){
		while(rt>=0&&arr[i]>arr[que[rt]]){
			rt--;
		}
		if(rt<0||arr[i]>arr[que[rt]]){
			que[++rt]=i;
		}
	}
	int m=n-len+1;
	maxi[0]=arr[que[0]];
	for(int i=1;i<m;i++){
		while(que[ff]<i){
			ff++;
		}
		while(rt>=ff&&arr[i+len-1]>arr[que[rt]]){
			rt--;
		}
		if(rt<ff||arr[i+len-1]>arr[que[rt]]){
			que[++rt]=i+len-1;
		}
		maxi[i]=arr[que[ff]];
	}
}

int main(){
	while(scanf("%d%d", &n, &len)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d", arr+i);
		}
		get_mini();
		get_maxi();
		n-=len-1;
		for(int i=0;i<n;i++){
			printf("%d ", mini[i]);
		}
		puts("");
		for(int i=0;i<n;i++){
			printf("%d ", maxi[i]);
		}
		puts("");
	}
	return 0;
}
