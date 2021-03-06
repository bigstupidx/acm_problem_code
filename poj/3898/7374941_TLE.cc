/* 
 * File:   pku-3898.cpp
 * Author: xhSong
 * Created on 2010年8月7日, 上午10:35
 * Time Complexity :
 * Space Complexity : 
 * Describe : 
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 1002
#define inf 0x0f0f0f0f

using namespace std;

char p[N], s[N * 10];

int f[N][N * 10];

int main(int argc, char** argv) {
    while(scanf("%s%s", p + 1, s + 1) != EOF) {
        int lenp = strlen(p + 1), lens = strlen(s + 1);
        memset(f, 0x0f, sizeof(f));
        for(int j = 0; j <= lens; ++j) {
            f[0][j] = 0;
        }
        for(int i = 1; i <= lenp; ++i) {
            for(int j = 1; j <= lens; ++j) {
                if(p[i] == '?') {
                    f[i][j] = min(f[i][j], f[i - 1][j]);
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + s[j] - 'a' + 1);
                    f[i][j] = min(f[i][j], f[i][j - 1] + s[j] - 'a' + 1);
                }
                else if(p[i] == '*') {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + s[j] - 'a' + 1);
                }
                else if(p[i] == s[j]) {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + s[j] - 'a' + 1);
                }
            }
        }
        int ans = inf;
        for(int j = 0; j <= lens; ++j) {
            ans = min(ans, f[lenp][j]);
        }
        if(ans == inf) {
            puts("-1");
        }
        else {
            printf("%d\n", ans);
        }
    }
    return 0;
}

