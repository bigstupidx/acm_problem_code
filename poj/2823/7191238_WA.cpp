#include <cstdio>
#include <cstring>
#define maxn 1000010

int n, len, maxi[maxn], mini[maxn], que[maxn], arr[maxn];

void get_mini() {
	int ff = 0, rt = 0;
	que[0] = 0;
	for (int i = 0; i < len; i++) {
		while (rt >= 0 && arr[i] < arr[que[rt]]) {
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
		while (ff <= rt && arr[i + len - 1] < arr[que[rt]]) {
			rt--;
		}
		que[++rt] = i;
		mini[i] = arr[que[ff]];
	}
}

void get_maxi() {
	int ff = 0, rt = 0;
	que[0] = 0;
	for (int i = 0; i < len; i++) {
		while (rt >= 0 && arr[i] > arr[que[rt]]) {
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
		while (ff <= rt && arr[i + len - 1] > arr[que[rt]]) {
			rt--;
		}
		que[++rt] = i;
		maxi[i] = arr[que[ff]];
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &len) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
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
