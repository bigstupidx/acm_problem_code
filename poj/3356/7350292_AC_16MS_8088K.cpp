#include <cstdio>
#include <algorithm>
#define N 3000

using namespace std;
char s[N], t[N];

int f[N][N];

int main() {
    int n, m;
    while(scanf("%d%s%d%s", &n, s + 1, &m, t + 1) != EOF) {
        for(int i = 0; i <= n; ++i) {
            f[i][0] = i;
        }
        for(int j = 0; j <= m; ++j) {
            f[0][j] = j;
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s[i] == t[j]) {
                    f[i][j] = f[i - 1][j - 1];
                }
                else {
                    f[i][j] = min(f[i][j - 1], f[i - 1][j]) + 1;
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
                }
            }
        }
        printf("%d\n", f[n][m]);
    }
    return 0;
}