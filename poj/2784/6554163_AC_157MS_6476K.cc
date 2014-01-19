/* 
 * File:   main.cpp
 * Author: wangjunyong
 *
 * Created on 2010年3月12日, 上午9:09
 */

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, va;

    bool operator<(const edge & a)const {
        return a.va>va;
    }
} edg[600002];
vector<int>sub[9];
int par[1002], n, subs, m, sel[9];

struct node {
    int x;
    int y;
} nod[1002];

int Distance(int i, int j) {
    int xx = nod[i].x - nod[j].x;
    int yy = nod[i].y - nod[j].y;
    return xx * xx + yy*yy;
}

int Find(int x) {
    if (par[x] == -1)
        return x;
    return par[x] = Find(par[x]);
}

int kruskral(int nn) {
    int ans = 0, cnt = nn;
    for (int i = 0; i < m; i++) {
        int ii = Find(edg[i].u);
        int jj = Find(edg[i].v);
        if (ii != jj) {
            par[ii] = jj;
            ans += edg[i].va;
            if (++cnt == n)break;
        }
    }
    return ans;
}

int main() {
    while (scanf("%d%d", &n, &subs) != EOF) {
        for (int i = 0; i < 9; i++)sub[i].clear();
        for (int i = 0; i < subs; i++) {
            int tem;
            scanf("%d", &m);
            scanf("%d", &tem);
            sub[i].push_back(m);
            sub[i].push_back(tem);
            for (int j = 0; j < m; j++) {
                scanf("%d", &tem);
                sub[i].push_back(tem);
            }
        }
        for (int i = 0; i < n; i++)
            scanf("%d%d", &nod[i].x, &nod[i].y);
        m = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edg[m].u = i + 1;
                edg[m].v = j + 1;
                edg[m++].va = Distance(i, j);
            }
        }
        sort(edg, edg + m);
        int fibs = 1, i = 0, ans = 1000000000;
        while (i < subs) {
            fibs *= 2;
            i++;
        }
        for (i = 0; i < fibs; i++) {
            int nn = i, j = 0, tem = 0, cnt = 1;
            memset(sel, 0, sizeof (sel));
            while (nn) {
                sel[j] = nn % 2;
                nn /= 2;
                j++;
            }
            memset(par, -1, sizeof (par));
            for (j = 0; j < subs; j++) {
                if (sel[j]) {
                    tem += sub[j][1];
                    for (int k = 1; k < sub[j][0]; k++) {
                        int ii = Find(sub[j][k + 1]);
                        int jj = Find(sub[j][k + 2]);
                        if (ii != jj) {
                            par[ii] = jj;
                            cnt++;
                        }
                    }
                }
            }
            //printf("%d ",tem);
            tem += kruskral(cnt);
            //printf("%d\n",tem);
            if (tem < ans)
                ans = tem;
        }
        printf("%d\n", ans);
    }
    return 0;
}
