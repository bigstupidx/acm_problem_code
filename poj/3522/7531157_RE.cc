#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct Tree {
	int a;
	int b;
	int len;
} node[10000];

bool Cmp(Tree n1, Tree n2) {
	if (n1.len <= n2.len) return true;
	return false;
}

int n, k, f[110];

int FindSet(int x) {
	if (f[x] == -1)return x;
	return f[x] = FindSet(f[x]);
}

int main() {
	while (scanf("%d%d", &n, &k) != EOF) {
		
		if (n == 0 && k == 0) break;

		for (int i = 0; i < k; i++) {
			scanf("%d%d%d", &node[i].a, &node[i].b, &node[i].len);
		}

		sort(node, node + k, Cmp);

		int ans = 1000000000;

		for (int i = 0; i < k; i++) {
			memset(f, -1, sizeof (f));
			int num = 1;
			bool state = false;
			for (int p = i; p < k; p++) {
				int fx = FindSet(node[p].a);
				int fy = FindSet(node[p].b);
				if (fx != fy) {
					f[fx] = fy;
					if (++num == n) {
						int cur = node[p].len - node[i].len;
						ans = ans < cur ? ans : cur;
						state = true;
						break;
					}
				}
			}
			if (!state)break;
		}
		if (ans == 1000000000)
			puts("-1");
		else
			printf("%d\n", ans);
	}
	//system("pause");
	return 0;
}
