#include <cstdio>
#include <cstring>
#define MAXN 1000010

int n, len, arr[MAXN], que[MAXN];

void get_mini() {
	int head = 0, tail = 0;
	que[0] = 0;
	for (int i = 1; i < len - 1; i++) {
		while (tail >= 0 && arr[i] < arr[que[tail]]) {
			tail--;
		}
		que[++tail] = i;
	}
	for (int i = len - 1; i < n; i++) {
		while (head <= tail && que[head] < i - len + 1)head++;
		while (tail >= head && arr[i] < arr[que[tail]]) {
			tail--;
		}
		que[++tail] = i;
		printf("%d ", arr[que[head]]);
	}
	puts("");
}

void get_maxi() {
	int head = 0, tail = 0;
	que[0] = 0;
	for (int i = 1; i < len - 1; i++) {
		while (tail >= 0 && arr[i] > arr[que[tail]]) {
			tail--;
		}
		que[++tail] = i;
	}
	for (int i = len - 1; i < n; i++) {
		while (head <= tail && que[head] < i - len + 1)head++;
		while (tail >= head && arr[i] > arr[que[tail]]) {
			tail--;
		}
		que[++tail] = i;
		printf("%d ", arr[que[head]]);
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
