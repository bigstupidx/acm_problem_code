#include <cstdio>
#include <cstring>

struct edge {
    int to;
    edge *next;
} edg[40010], *vert[502];

bool cut[502];
int n, m, flag[502], color[502], anc[502], dep[502], par[502];

void add_edge(int x, int y, int &top) {
    edge *p = &edg[++top];
    p->to = y;
    p->next = vert[x];
    vert[x] = p;
}

int Find(int x) {
    if (par[x] == -1) {
	return x;
    }
    return par[x] = Find(par[x]);
}

void DFS(int k_father, int k, int depth) {
    color[k] = 1;
    anc[k] = dep[k] = depth;
    int tot = 0;
    for (edge *p = vert[k]; p; p = p->next) {
	int i = p->to;
	if(flag[i])continue;
	if (i != k_father && color[i] == 1) {
	    anc[k] = anc[k] > dep[i] ? dep[i] : anc[k];
	}
	else if (color[i]==0) {
	    tot++;
	    DFS(k, i, depth + 1);
	    anc[k] = anc[i] > anc[k] ? anc[k] : anc[i];
	    if (k_father == -1 && tot > 1 || k_father != -1 && anc[i] > dep[k]) {
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
	for (int i = 0; i < m; i++) {
	    int u, v;
	    scanf("%d%d", &u, &v);
	    add_edge(u, v, top);
	    add_edge(v, u, top);
	    int ii = Find(u);
	    int jj = Find(v);
	    if (ii != jj) {
		par[ii] = jj;
		cnt--;
	    }
	}
	int xflag = 0;
	if (cnt != 1)xflag = 1;
	memset(flag, 0, sizeof (flag));
	for (int i = 0; i < n && !xflag; i++) {
	    flag[i] = 1;
	    memset(dep, 0, sizeof (dep));
	    memset(anc, 0, sizeof (anc));
	    memset(cut, 0, sizeof (cut));
	    memset(color, 0, sizeof (color));
	    DFS(-1, (i + 1) % n, 1);
	    for (int j = 0; j < n; j++) {
		if (i == j)continue;
		if (cut[j]||!color[j]) {
		    xflag = 1;
		    break;
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
