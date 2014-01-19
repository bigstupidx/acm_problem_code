#include <cstdio>
#include <cstring>

struct edge {
	int to;
	edge *next;
} edg[2000010], *vert[10010];

int n, m, hash[10010], que[10010], visit[10010];

inline void add_edge(int x, int y, int &top) {
	edge *p = &edg[++top];
	p->to = y;
	p->next = vert[x];
	vert[x] = p;
}

inline int get_num() {
	char ch;
	int ans = 0;
	while ((ch = getchar()) != EOF) {
		if (ch <= '9' && ch >= '0')break;
	}
	ans = ch - '0';
	while ((ch = getchar())) {
		if (ch > '9' || ch <= '0')break;
		ans = (ans << 3)+(ans << 1) + ch - '0';
	}
	return ans;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int nca = 1;
	while (scanf("%d%d", &n, &m), n || m) {
		for (int i = 1; i <= n; i++) {
			vert[i] = NULL;
			hash[i] = 0;
		}
		int top = -1;
		for (int x, y, i = 0; i < m; i++) {
			x = get_num();
			y = get_num();
			add_edge(x, y, top);
			add_edge(y, x, top);
		}
		top = 1;
		visit[1] = nca;
		que[1] = 1;
		int cnt = 1;
		int ans = 0;
		//		for(int i=1;i<=n;i++){
		//			for(edge *p=vert[i];p;p=p->next){
		//				printf("%d ", p->to);
		//			}
		//			puts("");
		//		}
		while (top > 0) {
			int s = que[top--];
			ans++;
			for (edge *p = vert[s]; p; p = p->next) {
				hash[p->to] = cnt;
			}
			for (int i = 2; i <= n; i++) {
				if (visit[i] != nca && hash[i] != cnt) {
					visit[i] = nca;
					que[++top] = i;
				}
			}
			cnt++;
		}
		printf("Case %d: %d\n", nca++, ans - 1);
	}
	return 0;
}
