#include <cstdio>
#include <cstring>
#define maxn 1000010

int n, len, arr[maxn], mini[maxn], maxi[maxn], que[maxn];

void get_mini() {
	int ff = 0, rt = 0;
	que[0] = 0;
	for (int i = 1; i < len; i++) {
		while (rt >= 0 && arr[i] <= arr[que[rt]]) {
			rt--;
		}
		que[++rt] = i;
	}
	mini[0] = arr[que[0]];
	int m = n - len + 1;
	for (int i = 1; i < m; i++) {
		while (ff <= rt && que[ff] < i) {
			ff++;
		}
		while (rt >= ff && arr[i + len - 1] <= arr[que[rt]]) {
			rt--;
		}
		que[++rt] = i + len - 1;
		mini[i] = arr[que[ff]];
	}
}

void get_maxi() {
	int ff = 0, rt = 0;
	que[0] = 0;
	for (int i = 1; i < len; i++) {
		while (rt >= 0 && arr[i] >= arr[que[rt]]) {
			rt--;
		}
		que[++rt] = i;
	}
	maxi[0] = arr[que[0]];
	int m = n - len + 1;
	for (int i = 1; i < m; i++) {
		while (ff <= rt && que[ff] < i) {
			ff++;
		}
		while (ff <= rt && arr[i + len - 1] >= arr[que[rt]]) {
			rt--;
		}
		que[++rt] = i + len - 1;
		maxi[i] = arr[que[ff]];
	}
}

int get_num()
{
    char ch;
    while (ch=getchar(),ch==10||ch==32);
	int sign=1, ans=ch-48;
	if(ch=='-'){
		sign=-1;
		ans=0;
	}
    while ((ch=getchar())!=EOF&&(ch>='0'&&ch<='9'))
    {
        ans*=10;
        ans+=ch-'0';
    }
    return ans*sign;
}

int main() {
	while (scanf("%d%d", &n, &len) != EOF) {
		for(int i=0;i<n;i++){
			arr[i]=get_num();
		}
		get_mini();
		get_maxi();
		n -= len - 1;
		for (int i = 0; i < n; i++) {
			printf("%d ", mini[i]);
		}
		puts("");
		for (int i = 0; i < n; i++) {
			printf("%d ", maxi[i]);
		}
		puts("");
	}
	return 0;
}
