#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 100010

using namespace std;

int arr[MAXN], c[MAXN];

int xfind(int top, int x) {
	int left = 0, right = top - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (c[mid] >= x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int temp, nca = 1;
	while (scanf("%d", &temp) != EOF) {
		if (temp == -1)
			break;
		int ans = 0, n = 1;
		c[0] = arr[0] = temp;
		while (scanf("%d", &arr[n]) != EOF) {
			if (arr[n] == -1)
				break;
			n++;
		}
		for (int i = 0; i < n; i++) {
			int index = xfind(ans, arr[i]);
			c[index] = arr[i];
			if (index == ans)
				++ans;
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n", nca++, ans);
	}
	return 0;
}
