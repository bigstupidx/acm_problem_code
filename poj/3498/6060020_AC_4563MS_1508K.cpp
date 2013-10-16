#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 205;
const int INF = 999999999;

struct Point{
double x, y;
int co, m;
};
Point arr[MAXN];
int n, mat[2*MAXN][2*MAXN], tot;
double d;
int que[2*MAXN], pre[MAXN], head, tail;
int f[2*MAXN][2*MAXN];
int ans[MAXN], len;

void input ()
{
int i;

scanf ("%d%lf", &n, &d);
tot = 0;
for (i = 1; i <= n; i++)
{
   scanf ("%lf%lf%d%d", &arr[i].x, &arr[i].y, &arr[i].co, &arr[i].m);
   tot += arr[i].co;
}
}
double Dis (int i, int j)
{
return sqrt ((arr[i].x - arr[j].x) * (arr[i].x - arr[j].x)
   + (arr[i].y - arr[j].y) * (arr[i].y - arr[j].y));
}
void create ()
{
int i, j;

memset (mat, 0, sizeof (mat));
for (i = 1; i <= n; i++)
{
   for (j = i + 1; j <= n; j++)
    if (Dis (i, j) <= d)
     mat[i][j + n] = mat[j][i + n] = INF;
   mat[i + n][i] = arr[i].m;
   mat[0][i + n] = arr[i].co;
}

}
int find (int t)
{
int u, v, i;

memset (pre, -1, sizeof (pre));
head = tail = 0;
que[0] = 0;
while (head <= tail)
{
   u = que[head];
   for (v = 1; v <= 2 * n; v++)
    if (mat[u][v] - f[u][v] > 0 && pre[v] == -1)
    {
     pre[v] = u;
     que[++tail] = v;
     if (v == t)
      return 1;
    }
   head++;
}
return 0;
}
int max_flow (int t)
{
int k, flow = 0, mini;

while (find (t))
{
   mini = INF;
   k = t;
   while (k != 0)
   {
    if (mat[pre[k]][k] - f[pre[k]][k] < mini)
     mini = mat[pre[k]][k] - f[pre[k]][k];
    k = pre[k];
   }
   k = t;
   while (k != 0)
   {
    f[pre[k]][k] += mini;
    f[k][pre[k]] -= mini;
    k = pre[k];
   }
   flow += mini;
}
return flow;
}
void solve()
{
int i, tmp;

create ();
len = 0;
for (i = 1; i <= n; i++)
{
   memset (f, 0, sizeof (f));
   tmp = max_flow(i + n);
   if (tmp == tot)
    ans[len++] = i - 1;
}
if (len == 0)
{
   printf ("-1\n");
   return;
}
for (i = 0; i < len - 1; i++)
   printf ("%d ", ans[i]);
printf ("%d\n", ans[i]);
}
int main ()
{
int T;

scanf ("%d", &T);
while (T--)
{
   input ();
   solve ();
}
return 0;
}