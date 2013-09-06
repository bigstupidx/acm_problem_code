#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 30;

struct node{
    int to, d, next;
} e[MAXN*4];

int n, dis[MAXN], vert[MAXN], vvert[MAXN];
int q[MAXN], cnt[MAXN], t[MAXN], r[MAXN];
bool mk[MAXN];

void addedge(int u, int v, int d, int &top)
{
    e[++top].to=v, e[top].d=d;
    e[top].next=vert[u], vert[u]=top;
}

bool solve(int mid)
{
    for (int i=0; i<24; ++i) dis[i]=t[0], cnt[i]=0, q[i]=i, mk[i]=1;
    if(dis[23]<mid) dis[23]=mid;
    for (int h=0, t=24; h!=t; h=(h+1)%MAXN)
    {
        int u=q[h];
        for (int i=vert[u]; i!=-1; i=e[i].next)
        {
            int v=e[i].to, tmp=dis[u]+e[i].d;
            if (tmp < dis[v])
            {
                dis[v]=tmp;
                if (++cnt[v]==24) return 0;
                if (!mk[v]) mk[q[t]=v]=1, t=(t+1)%MAXN;
            }
        }
        mk[u]=0;
    }
    return 1;
}

void init()
{
    for (int i=1; i<=24; ++i) scanf("%d", r+i);
    int n;
    scanf("%d", &n);
    for (int i=1; i<=24; ++i) t[i]=0;
    for (int i=0; i<n; ++i)
    {
        int x;
        scanf("%d", &x);
        ++t[++x];
    }
    int st=0, ed=n;
    while (st<=ed)
    {
        int mid=(st+ed)>>1, top=-1;
        memset(vert, -1, sizeof(vert));
        for (int i=1; i<=24; ++i)
        {
            addedge(i-1, i, t[i], top);
            addedge(i, i-1, 0, top);
        }
        for (int i=9; i<=24; ++i)
            addedge(i, i-8, -r[i], top);
        for (int i=1; i<=8; ++i)
            addedge(i, i+16, mid-r[i], top);
        addedge(24, 0, -mid, top);
        if (solve(mid)) ed=mid-1;
        else st=mid+1;
    }
    ++ed;
    if (ed>n) puts("No Solution");
    else printf("%d\n", ed);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i=0; i<T; ++i) init();
    return 0;
}
