#include <cstdio>
#include <cstring>

int cnt[1000], f[1000];

bool letter(char c) {
    if(c <= 'z' && c >= 'a') {
        return true;
    }
    if(c <= 'Z' && c >= 'A') {
        return true;
    }
    return false;
}

int find(int x) {
    return f[x] == x? x : f[x] = find(f[x]);
}

int main() {
    char a, b, c, ca[10];
    bool p;
    while(scanf("%s", ca) != EOF) {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i < 255; ++i) {
            f[i] = i;
        }
        int m = 0;
        while(1) {
            while(c = getchar(), !letter(c) && c != '}');
            if(c == '}') {
                break;
            }
            m ++;
        }
        p = 0;
        while(1) {
            while(c = getchar(), !letter(c) && c != '}');
            if(c == '}') {
                break;
            }
            if(p) {
                b = c;
                cnt[a] ++;
                cnt[b] ++;
                int ra = find(a), rb = find(b);
                if(ra != rb) {
                    f[ra] = rb;
                    m --;
                }
                p = 0;
            }
            else {
                p = 1;
                a = c;
            }
        }
        if(m == 1) {
            int cntodd = 0;
            for(int i = 0; i < 255; ++i) {
                cntodd = cntodd + cnt[i] % 2;
            }
            if(cntodd == 2) {
                printf("Yes No\n");
            }else if(cntodd == 0) {
                printf("No Yes\n");
            }
            else printf("No No\n");
        }
        else {
            printf("No No\n");
        }
    }
}