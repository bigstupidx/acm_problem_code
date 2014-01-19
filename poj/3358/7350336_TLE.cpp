#include <cstdio>
#include <map>

using namespace std;

long long gcd(long long a, long long b) {
    long long r;
    while (b) r = a % b, a = b, b = r;
    return a;
}

int main() {
    int tp, tq, cntcase = 0;
    long long p, q, g;
    while(scanf("%d/%d", &tp, &tq) != EOF) {
        p = tp, q = tq;
        if(p == 0) {
            printf("Case #%d: %d,%d\n", ++cntcase, 1, 1);
            continue;
        }
        g = gcd(q, p);
        p /= g, q /= g;
        map<long long, int> c;
        c.insert(make_pair((p << 32) + q, 1));
        for(int i = 2; ; ++i) {
            if(q % 2) {
                p = p * 2 % q;
            }
            else {
                q /= 2;
                p = p % q;
            }
            map<long long, int> ::iterator pos;
            pos = c.find((p<<32) + q);
            if(pos != c.end()) {
                printf("Case #%d: %d,%d\n", ++cntcase, pos->second, i - pos->second);
                break;
            }
            c.insert(make_pair((p<<32) + q, i));
        }
    }
    return 0;
}