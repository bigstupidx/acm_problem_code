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

int n, k, par[110];

int FindSet(int x) {
	if (par[x] == -1)return x;
	return par[x] = FindSet(par[x]);
}

int main() {
	while (scanf("%d%d", &n, &k), n || k) {
		for (int i = 0; i < k; i++) {
			scanf("%d%d%d", &node[i].a, &node[i].b, &node[i].len);
		}

		sort(node, node + k, Cmp);

		int ans = 1000000000;

		for (int i = 0; i < k; i++) {
			memset(par, -1, sizeof (par));
			int num = 1;
			bool stat = false;
			for (int j = i; j < k; j++) {
				int ii = FindSet(node[j].a);
				int jj = FindSet(node[j].b);
				if (ii != jj) {
					par[ii] = jj;
					if (++num == n) {
						int cur = node[j].len - node[i].len;
						ans = ans < cur ? ans : cur;
						stat = true;
						break;
					}
				}
			}
			if (!stat)break;
		}
		if (ans == 1000000000)
			puts("-1");
		else
			printf("%d\n", ans);
	}
	//system("pause");
	return 0;
}
