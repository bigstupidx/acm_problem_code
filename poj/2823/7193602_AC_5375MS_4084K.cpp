#include <cstdio>
#include <cstring>
#define maxn 1000010

int n, len, que[maxn], arr[maxn];

void get_mini() {
	int ff = 0, rt = 0;
	que[0] = 0;
	for (int i = 1; i < len - 1; i++) {
		while (rt >= ff && arr[i] <= arr[que[rt]]) {
			rt--;
		}
		que[++rt] = i;
	}
	for (int i = len - 1; i < n; i++) {
		if (que[ff] < i - len + 1)ff++;
		while (rt >= ff && arr[i] <= arr[que[rt]]) {
			rt--;
		}
		que[++rt] = i;
		printf("%d ", arr[que[ff]]);
	}
	puts("");
}

void get_maxi() {
	int ff = 0, rt = 0;
	que[0] = 0;
	for (int i = 1; i < len - 1; i++) {
		while (rt >= ff && arr[i] >= arr[que[rt]]) {
			rt--;
		}
		que[++rt] = i;
	}
	for (int i = len - 1; i < n; i++) {
		if (que[ff] < i - len + 1)ff++;
		while (rt >= ff && arr[i] >= arr[que[rt]]) {
			rt--;
		}
		que[++rt] = i;
		printf("%d ", arr[que[ff]]);
	}
	puts("");
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &len) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
		}
		get_mini();
		get_maxi();
	}
	return 0;
}
