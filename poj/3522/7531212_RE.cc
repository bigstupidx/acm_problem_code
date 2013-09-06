#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct Tnode {
	int a;
	int b;
	int len;
} nod[10000];

bool Cmp(const Tnode &n1, const Tnode &n2) {
	if (n1.len <= n2.len) return true;
	return false;
}

int n, k, par[110];

int Find(int x) {
	if (par[x] == -1)return x;
	return par[x] = Find(par[x]);
}

int main() {
	while (scanf("%d%d", &n, &k), n || k) {
		for (int i = 0; i < k; i++) {
			scanf("%d%d%d", &nod[i].a, &nod[i].b, &nod[i].len);
		}

		sort(nod, nod + k, Cmp);

		int ans = 1000000000;

		for (int i = 0; i < k; i++) {
			memset(par, -1, sizeof (par));
			int num = 1;
			bool stat = false;
			for (int j = i; j < k; j++) {
				int ii = Find(nod[j].a);
				int jj = Find(nod[j].b);
				if (ii != jj) {
					par[ii] = jj;
					if (++num == n) {
						int cur = nod[j].len - nod[i].len;
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
