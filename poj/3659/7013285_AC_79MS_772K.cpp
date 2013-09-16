#include <cstdio>
#include <vector>
#define Min(a,b) (a<b?a:b)
using namespace std;

int f[10010][3];

vector<int> edge[10010];

void DFS(int x, int form) {
    f[x][0] = 0;
    f[x][1] = f[x][2] = 1;
    for(int i = 0; i < edge[x].size(); ++i) {
        int to = edge[x][i];
        if(to != form) {
            DFS(to, x);
            int temp = Min(f[to][1], f[to][2]);
            f[x][1] = Min(f[x][0] + f[to][2], f[x][1] + temp);
            f[x][0] += f[to][1];
            f[x][2] += Min(temp, f[to][0]);
        }
    }
}

int main()
{
    int n, x, y;
    scanf("%d",&n);
    for(int i = 1;i<n;i++) {
        scanf("%d%d",&x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    DFS(1, 0);
    printf("%d\n",Min(f[1][1], f[1][2]));
    return 0;
}

