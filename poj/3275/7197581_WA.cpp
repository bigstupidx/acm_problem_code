#include <cstdio>
#include <cstring>

bool map[1001][1001];

int main() {
    int n, m, i, j, k, x, y, ans;
    while(scanf("%d%d", &n, &m) != EOF) {
        memset(map, 0, sizeof(map));
        for(i = 0; i < n; ++i) {
            scanf("%d%d", &x, &y);
            map[x][y] = 1;
        }
        for(k = 1; k <= n; ++k) 
            for(i = 1; i <= n; ++i) 
                if(map[i][k]) for(j = 1; j <= n; ++j) 
                        if(map[k][j]) map[i][j] = 1;
        ans = 0;
        for(i = 1; i <= n; ++i) 
            for(j = i + 1; j <= n; ++j) 
                if(!map[i][j] && !map[j][i]) ans ++;
        printf("%d\n", ans);
    }
}
