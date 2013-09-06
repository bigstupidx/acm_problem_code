#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

char str[3];
int n, cnt, mm;
bool visit[1002], map[1002][1002];

struct edge {
    int to;
    int id;
    edge *next;
} edg[1000010], *vert[1002];

priority_queue <int> Q;

void add_edge(int x, int y, int &top) {
	//printf("%d \n", top);
    edge *p = &edg[++top];
    p->to = y;
    p->id = top;
    p->next = vert[x];	vert[x] = p;

    p = &edg[++top];
    p->to = x;
    p->id = top;
    p->next = vert[y];	vert[y] = p;
}

void delete_edge(int x, int y) {
    edge *q = NULL, *p;
    for (p = vert[x]; p; q = p, p = p->next) {
		if (p->to == y) {
	    	break;
		}
    }
    if(p->to==y){
		if (q) {
			cnt++;
			Q.push(q->next->id);
			q->next = q->next->next;
    	}
		else {
			cnt++;
			Q.push(p->id);
			vert[x] = vert[x]->next;
    	}
	}
    q = NULL;
    for (p = vert[y]; p; p = p->next) {
		if (p->to == x) {
	    	break;
		}
    }
    if(p->to==x){
    	if (q) {
			q->next = q->next->next;
    	}
		else {
			vert[y] = vert[y]->next;
    	}
	}
}

bool DFS(int s, int t) {
    if (s == t)return true;
    visit[s] = true;
    for (edge *p = vert[s]; p; p = p->next) {
		if (!visit[p->to] && DFS(p->to, t)) {
	    	return true;
		}
    }
    return false;
}

int main() {
    int top = -1;
    while(!Q.empty())Q.pop();
    scanf("%d%d", &n, &mm);
    while (mm--) {
		int u, v;
		scanf("%s%d%d", str, &u, &v);
		if (str[0] == 'Q') {
	    	memset(visit, false, sizeof (visit));
	    	if (u==v||map[u][v]||DFS(u, v)) {
				puts("Y");
	    	}
			else {
				puts("N");
	    	}
		}
		else if (str[0] == 'I') {
			if(u==v)continue;
	    	if (map[u][v])continue;
	    	map[u][v] = true;
	    	map[v][u] = true;
	    	if (!cnt) {
				add_edge(u, v, top);
	    	}
			else {
				int x = Q.top();
				Q.pop();
				if (x % 2) {
		    		x-=3;
		    		add_edge(u, v, x);
				}
				else {
		    		x--;
		    		add_edge(u, v, x);
				}
	    	}
		}
		else {
	    	if (!map[u][v])continue;
	    	map[u][v] = false;
	    	map[v][u] = false;
	    	delete_edge(u, v);
		}
    }
    //system("pause");
    return 0;
}
