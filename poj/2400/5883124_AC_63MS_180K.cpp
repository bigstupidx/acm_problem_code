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

int n ,top ,limit;
int choose[MAXN];

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
			if(lx[i]<g[i][j])lx[i] = g[i][j];
	int match = 0;
	while (match != N)
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (lx[i] + ly[j] == g[i][j])
                    w[i][j] = true; 
                else w[i][j] = false;
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
					if(delta>lx[i] + ly[j] - g[i][j])
                        delta = lx[i] + ly[j] - g[i][j];
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


void DFS_Trace(int s,int sum)
{
    if(sum>limit)return ;
    if(s==n){
        if(sum!=limit)return ;
        printf("Best Pairing %d\n",top++);
        for(int i=0;i<n;i++)
            printf("Supervisor %d with Employee %d\n",i+1,choose[i]+1);
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(!cy[i])
        {
            cy[i]=1;
            choose[s]=i;
            DFS_Trace(s+1,sum+g[s][i]);
            cy[i]=0;
        }
    }
}
int main()
{
    int ncase;
    scanf("%d",&ncase);
    for(int ii=1;ii<=ncase;ii++)
    {
        int tem;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                scanf("%d",&tem);
                tem--;
                g[tem][i]=j;
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                scanf("%d",&tem);
                tem--;
                g[i][tem]+=j;
            }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
             //   printf("%d ",map[i][j]);
                g[i][j]=100-g[i][j];
            }
           // puts("");
        }
        M=N=n;
        limit=BestMatch();
        double ans=limit*0.5/n;
        printf("Data Set %d, Best average difference: %.6lf\n",ii,ans);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                g[i][j]=100-g[i][j];
        memset(cy,0,sizeof(cy));
        top=1;  DFS_Trace(0,0);
        puts("");
    }
    return 0;
}
