#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

int n, arr[1002];

int main() {
	while (scanf("%d", &n) != EOF) {
		map <int, int> mp;
		map <int, int> ::iterator p;
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			arr[i] = x;
			mp[y] = i;
		}
		for (int i = 0; i < n; i++) {
			p = mp.find(arr[i]);
			arr[i] = p->second;
//			printf("%d ", arr[i]);
		}
//		puts("");
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[j] < arr[i]) {
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
