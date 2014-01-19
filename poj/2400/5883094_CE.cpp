#include<cstdio>
#include<cstring>
#define INF 0x7fffffff
#define MAXN 15
#define MAXM 15

int N,M;
bool w[MAXN][MAXM];
int g[MAXN][MAXM];
int lx[MAXN], ly[MAXM];
int ux[MAXN], uy[MAXM];
bool cx[MAXN], cy[MAXM];

int n ,tot ,limit;
int choose[MAXN];
bool used[MAXN];

bool findpath(int now)
{
	cx[now] = false;
	for (int i = 0; i < M; ++i)
		if (w[now][i] && !cy[i])
		{
			cy[i] = true;
			if (uy[i] == -1 || findpath(uy[i]))
			{
				ux[now] = i;
				uy[i] = now;
				return true;
			}
		}
	return false;
}

int BestMatch()
{
	memset(lx, 0, sizeof(lx));
	memset(ly, 0, sizeof(ly));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			lx[i] >?= g[i][j];
	int match = 0;
	while (match != N)
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (lx[i] + ly[j] == g[i][j]) w[i][j] = true; else w[i][j] = false;
		memset(ux, 0xff, sizeof(ux));
		memset(uy, 0xff, sizeof(uy));
		for (int i = 0; i < N; ++i)
		{
			memset(cx, true, sizeof(cx));
			memset(cy, false, sizeof(cy));
			if (!findpath(i)) break; else ++match;
		}
		if (match == N) break;
		int delta = INF;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (!cx[i] && !cy[j])
					delta <?= lx[i] + ly[j] - g[i][j];
		for (int i = 0; i < N; ++i)
			if (!cx[i]) lx[i] -= delta;
		for (int i = 0; i < M; ++i)
			if (cy[i]) ly[i] += delta;
		match = 0;
	}
	int temp = 0;
	for (int i = 0; i < N; ++i) temp += lx[i];
	for (int i = 0; i < M; ++i) temp += ly[i];
	return 100 * N - temp;
}

void output()
{
	printf("Best Pairing %d\n" , ++tot);
	for (int i = 0; i < n ;++i)
		printf("Supervisor %d with Employee %d\n", i + 1, choose[i] + 1);
}

void DFS(int depth , int sum)
{
	if (sum > limit) return;
	if (depth == n)
	{
		output();
		return;
	}
	for (int i = 0; i < n; ++i)
		if (!used[i])
		{
			used[i] = true;
			choose[depth] = i;
			DFS(depth + 1, sum + g[depth][i]);
			used[i] = false;
		}
}

int main()
{
	int cases;
	scanf("%d",&cases);
	for (int ca = 1; ca <= cases; ++ca)
	{
		memset( g,  0 , sizeof(g));
		scanf("%d",&n);
		int x;
		for (int i = 0 ; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				scanf("%d",&x);
				--x;
				g[x][i] = j;
			}
		for (int i = 0 ; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				scanf("%d",&x);
				--x;
				g[i][x] += j;
			}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				g[i][j] = 100 - g[i][j];
		N = M = n;
		limit = BestMatch();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				g[i][j] = 100 - g[i][j];
		printf("Data Set %d, Best average difference: %.6lf\n",ca , limit / (n + n + 0.0));
		memset( used , false , sizeof(used));
		tot = 0;
		DFS(0 , 0);
		putchar('\n');
	}
}

