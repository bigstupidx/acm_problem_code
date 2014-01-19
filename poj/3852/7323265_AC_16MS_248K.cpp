#include <cstdio>
#include <map>
#include <string>
#include <cstring>

using namespace std;

char str[102][102];

int solve(int n) {
	int ans = 1;
	map <string, int> mp;
	map <string, int> ::iterator p;
	for (int i = 0; i < n; i++) {
		mp[str[i]] = 1;
	}
	while (1) {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			//printf("%s\n", str[i] + ans);
			if (str[i][ans] == 0) {
				flag = true;
				break;
			}
			p = mp.find(str[i] + ans);
			if (p == mp.end()) {
				mp[str[i] + ans] = 1;
			} else {
				flag = true;
				break;
			}
		}
		if (flag)break;
		ans++;
	}
	return ans - 1;
}

int main() {
	int n;
	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; i++) {
			scanf("%s", str[i]);
		}
		printf("%d\n", solve(n));
	}
	return 0;
}
