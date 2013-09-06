#include <cstdio>
#include <cstring>

struct edge {
	int to;
	edge *next;
} edg[2000010], *vert[10010];

int n, m, hash[10010], que[10010];
bool visit[10010];

inline int get_num() {
	char ch;
	int ans = 0;
	while ((ch = getchar()) == ' ' || ch == '\n');
	ans = ch - '0';
	while (true) {
		ch = getchar();
		if (ch > '9' || ch <= '0')break;
		ans = (ans << 3)+(ans << 1) + ch - '0';
	}
	return ans;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca = 1;
	while (scanf("%d%d", &n, &m), n || m) {
		int top = -1;
		memset(hash, 0, sizeof (hash));
		memset(vert, 0, sizeof (vert));
		memset(visit, 0, sizeof (visit));
		for (int x, y, i = 0; i < m; i++) {
			x = get_num();
			y = get_num();
			edge *p = &edg[++top];
			p->to = y;
			p->next = vert[x];
			vert[x] = p;

			p = &edg[++top];
			p->to = x;
			p->next = vert[y];
			vert[y] = p;
		}
		int lf = 0, rt = 0;
		visit[1] = true;
		que[0] = 1;
		int cnt = 1;
		int ans = 0;
		//		for(int i=1;i<=n;i++){
		//			for(edge *p=vert[i];p;p=p->next){
		//				printf("%d ", p->to);
		//			}
		//			puts("");
		//		}
		while (lf <= rt) {
			int s = que[lf++];
			ans++;
			for (edge *p = vert[s]; p; p = p->next) {
				hash[p->to] = cnt;
			}
			for (int i = 2; i <= n; i++) {
				if (!visit[i] && hash[i] != cnt) {
					visit[i] = true;
					que[++rt] = i;
				}
			}
			cnt++;
		}
		printf("Case %d: %d\n", nca++, ans - 1);
	}
	return 0;
}
