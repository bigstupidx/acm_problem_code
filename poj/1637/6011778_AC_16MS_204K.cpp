#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 210;
const int MAXM = 4000;
const int INF = 1 << 30;
struct Edge {
     int idx, flow;
     Edge *next, *opp;
};
Edge *adj[MAXN], memo[MAXM];
int mset, lv[MAXN];
void addEdgeProcess(int u, int v, int w) {
     Edge *ptr = &memo[mset ++];
     ptr -> idx = v;
     ptr -> flow = w;
     ptr -> next = adj[u];
     adj[u] = ptr;
}
void addEdge(int u, int v, int w) {
     addEdgeProcess(u, v, w);
     addEdgeProcess(v, u, 0);
     adj[u] -> opp = &memo[mset - 1];
     adj[v] -> opp = &memo[mset - 2];
}
bool bfs(int s, int t) {
     int head, tail, q[MAXN];
     head = tail = 0;
     q[tail ++] = s;
     for(int i = s; i <= t; i ++) lv[i] = -1;
     lv[s] = 0;
     while(head < tail) {
          int u = q[head ++];
          for(Edge *ptr = adj[u]; ptr; ptr = ptr -> next) {
               int v = ptr -> idx;
               if(lv[v] == -1 && ptr -> flow > 0) {
                    lv[v] = lv[u] + 1;
                    q[tail ++] = v;
                    if(v == t) return true;
               }
          }
     }
     return false;
}
int dicnic(int s, int t) {
     int max_flow = 0;
     int i, u, top, p[MAXM];
     Edge *pre[MAXN], *cur[MAXN];
     while(bfs(s, t)) {
          p[top = 1] = u = s;
          for(i = s; i <= t; i ++) cur[i] = adj[i];
          while(cur[s]) {
                if(u != t && cur[u] && cur[u] -> flow > 0 && lv[u] + 1 == lv[cur[u] -> idx]) {
                      int v = cur[u] -> idx; p[++ top] = v;
                      pre[v] = cur[u];
                      u = v;
                }else if(u == t) {
                      int mn = INF;
                      for(i = top; i > 1; i --) {
                            mn = min(mn, pre[p[i]] -> flow);
                      }
                      for(i = top; i > 1; i --) {
                            pre[p[i]] -> flow -= mn;
                            pre[p[i]] -> opp -> flow += mn;
                            if(pre[p[i]] -> flow == 0) top = i - 1;
                      }
                      u = p[top];
                      max_flow += mn;
                }else {
                      while(u != s && cur[u] == NULL) u = p[-- top];
                      cur[u] = cur[u] -> next;
                }
          }
     }
     return max_flow;
}
int main() {
     int casn;
     scanf("%d", &casn);
     while(casn --) {
          int i, m, n;
          int in[MAXN], out[MAXN];
          memset(in, 0, sizeof(in));
          memset(out, 0, sizeof(out));
          scanf("%d %d", &m, &n);
          int s = 0, t = m + 1;
          for(i = s; i <= t; i ++) adj[i] = 0;
          int u, v, tag;
          mset = 0;
          for(i = 1; i <= n; i ++) {
               scanf("%d %d %d", &u, &v, &tag);
               if(u == v) continue;
               in[v] ++; out[u] ++;
               if(tag == 0) addEdge(u, v, 1);
          }
          int sum = 0;
          for(i = 1; i <= m; i ++) {
               out[i] -= in[i];
               if(out[i] & 1) break;
               out[i] >>= 1;
               if(out[i] > 0) {
                     sum += out[i];
                     addEdge(s, i, out[i]);
               }else if(out[i] < 0) {
                     addEdge(i, t, -out[i]);
               }
          }
          if(i == m + 1 && sum == dicnic(s, t)) printf("possible\n");
          else printf("impossible\n");
     }
     return(0);
}