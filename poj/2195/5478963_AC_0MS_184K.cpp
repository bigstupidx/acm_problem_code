#include <iostream>
#include <cmath>
using namespace std;
struct point
{
	int x;
	int y;
}l[111], r[111];

int n, m, ltop, rtop;
int pre[111] ;
int Left[111], Right[111];
int w[111][111];
char map[111][111];
int Max;
bool l_visit[111], r_visit[111];


int dfs(int u)
{
	int i, k;
	l_visit[u] = 1;
	for(i = 0; i < rtop; i++)
	{
		if(!r_visit[i] && Left[u] + Right[i] == w[u][i])
		{
			r_visit[i] = 1;
			k = pre[i];
			pre[i] = u;
			if(k == -1 || dfs(k) )
				return 1;
			pre[i] = k;
		}
	}
	return 0;
}
int KM_match()
{
	int i, j, k;
	int d;
	memset(pre, -1, sizeof(pre));
	for(i = 0; i < ltop; i++)
	{

		while(1)
		{	
			memset(l_visit, 0, sizeof(int)*ltop);
		memset(r_visit, 0, sizeof(int)*rtop);
			if(dfs(i))
				break;
			
			d = INT_MAX;
			for(j = 0; j < ltop; j++)
			{
				if(l_visit[j])
				{
		
					for(k = 0; k < rtop; k++)
					{
						if(!r_visit[k] && Left[j] + Right[k] - w[j][k] < d)
						{
							d = Left[j] + Right[k] - w[j][k];
						}
					}
				}
			}

			for(j = 0 ;j < ltop; j++)
			{
				if(l_visit[j])
					Left[j] -= d;
				if(r_visit[j])
					Right[j] += d;
			}
		}

	}
	int sum = 0;
	for(i = 0; i < rtop; i++)
		sum += w[ pre[i] ] [i];
	return -sum;
}
int main()
{
	int i, j;
	while(scanf("%d%d", &n, &m) != EOF && (n || m))
	{
		ltop = rtop = 0;
		for(i = 1; i <= n; i++)
		{
			scanf("%s", &map[i][1]);
		}
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				if(map[i][j] == 'm')
				{
					l[ltop].x = i;
					l[ltop].y = j;
					ltop++;
				}else if(map[i][j] == 'H')
				{
					r[rtop].x = i;
					r[rtop].y = j;
					rtop++;
				}
			}
		}
		for(i = 0; i < ltop; i++)
		{
			Max = -9999999;
			for(j = 0; j < rtop; j++)
			{
				w[i][j] = - (abs(l[i].x-r[j].x) + abs(l[i].y - r[j].y) );
				if(w[i][j] > Max)
					Max = w[i][j];
			}
			Left[i] = Max;
			Right[i] = 0;
		}
		printf("%d\n", KM_match());

	}
	return 0;
} 