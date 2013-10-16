#include <cstdio>
#include <cstring>
#define MAXN 502

struct edge {
    int to;
    edge *next;
} edg[40010], *vert[MAXN];

bool cut[MAXN];
int n, m, color[MAXN], dep[MAXN], anc[MAXN], par[MAXN], flag[MAXN];

void add_edge(int x, int y, int &top) {
    edge *p = &edg[++top];
    p->to = y;
    p->next = vert[x]; vert[x] = p;
}

int my_find(int x) {
    if (par[x] == -1) {
	return x;
    }
    return par[x] = my_find(par[x]);
}

void DFS(int k_father, int k, int depth) {
    color[k] = 1;
    anc[k] = dep[k] = depth;
    int tot = 0;
    for (edge *p = vert[k]; p; p = p->next) {
	int i = p->to;
	if(flag[i])continue;
	if (i != k_father && color[i] == 1) {
	    anc[k] = dep[i] < anc[k] ? dep[i] : anc[k];
	}
	else if (color[i] == 0) {
	    tot++;
	    DFS(k, i, depth + 1);
	    anc[k] = anc[k] < anc[i] ? anc[k] : anc[i];
	    if (k_father == -1 && tot > 1 || k_father != -1 && anc[i] >= dep[k]) {
		cut[k] = true;
	    }
	}
    }
    color[k] = 2;
}

int main() {
    while (scanf("%d%d", &n, &m), n || m) {
	int top = -1, cnt = n;
	memset(par, -1, sizeof (par));
	memset(vert, 0, sizeof (vert));
	for (int u, v, ii, jj, i = 0; i < m; i++) {
	    scanf("%d%d", &u, &v);
	    add_edge(u, v, top);
	    add_edge(v, u, top);
	    ii = my_find(u);
	    jj = my_find(v);
	    if (ii != jj) {
		cnt--;
		par[ii] = jj;
	    }
	}

	int xflag = 0;
	if (cnt != 1)xflag = 1;
	for (int i = 0; i < n && !xflag; i++) {
	    flag[i] = 1;
	    memset(cut, 0, sizeof (cut));
	    memset(dep, 0, sizeof (dep));
	    memset(anc, 0, sizeof (anc));
	    memset(color, 0, sizeof (color));
	    DFS(-1, (i + 1) % n, 1);
	    for (int j = 0; j < n && !xflag; j++) {
		if (i == j)continue;
		if (cut[j] || !color[j]) {
		    xflag = 1;
		}
	    }
	    flag[i] = 0;
	}

	if (!xflag) {
	    puts("YES");
	}
	else {
	    puts("NO");
	}
    }
    return 0;
}
