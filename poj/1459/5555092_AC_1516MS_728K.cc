
#include <cstdio>
#include <cstring>
#define INF 1000000000
#define MAXN 210
struct
{
	int to, f, c, r, next;
}e[30020];
int a[MAXN], q[MAXN], p[MAXN][2], lev[MAXN];
int tail,n;
int dinic(int s, int t)
{
	int flow = 0;
	q[0] = s;
	while (1)
	{
		int head = -1, tail = 0;
		memset(lev, -1, sizeof(lev)); lev[s] = 0;
		while (head++ < tail)
			for (int i = a[q[head]]; i >= 0; i = e[i].next)
				if (lev[e[i].to] < 0 && e[i].c > e[i].f)
				{
					q[++tail] = e[i].to;
					lev[e[i].to] = lev[q[head]] + 1;
				}
		if (lev[t] < 0) return flow;
		p[0][0] = s; p[0][1] = a[s]; tail = 0;
		while (tail >= 0)
			if (p[tail][0] != t)
			{
				while (p[tail][1] >= 0)
				{
					if (lev[p[tail][0]] < lev[e[p[tail][1]].to] && e[p[tail][1]].c > e[p[tail][1]].f)
					{
						p[tail + 1][0] = e[p[tail][1]].to;
						p[tail + 1][1] = a[p[tail + 1][0]];
						tail++;
						break;
					}
					p[tail][1] = e[p[tail][1]].next;
				}
				if (p[tail][1] < 0)
				{
					tail--;
					p[tail][1] = e[p[tail][1]].next;
				}
			}
			else
			{
				int mini = INF,k;
				for (int i = 0; i < tail; i++)
					if (mini > e[p[i][1]].c - e[p[i][1]].f) mini = e[p[i][1]].c - e[p[i][1]].f;
				flow += mini;
				for (int i = tail - 1; i >= 0; i--)
				{
					e[p[i][1]].f += mini;
					e[e[p[i][1]].r].f-=mini;
					if (e[p[i][1]].f == e[p[i][1]].c) k = i;
				}
                                tail=k;
				p[tail][1] = e[p[tail][1]].next;
			}
	}
}
void add_edge(int x,int y,int z)
{
    e[++tail].to = y; e[tail].f = 0;
    e[tail].c = z; e[tail].r = tail + 1;
    e[tail].next = a[x]; a[x] = tail;

    e[++tail].to = x; e[tail].f = 0;
    e[tail].c = 0; e[tail].r = tail - 1;
    e[tail].next = a[y]; a[y] = tail;
}
int main()
{
    int np,nc,m;
    while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
    {
        int u,v,z,i;
        memset(a,-1,sizeof(a));
        tail=-1;
        for(i=0;i<m;i++){
            while(getchar()!='(');
            scanf("%d,%d)%d",&u,&v,&z);
            add_edge(u+1,v+1,z);
        }
        for(i=0;i<np;i++){
            while(getchar()!='(');
            scanf("%d)%d",&u,&z);
            add_edge(0,u+1,z);
        }
        for(i=0;i<nc;i++){
            while(getchar()!='(');
            scanf("%d)%d",&u,&z);
            add_edge(u+1,n+1,z);
        }
        printf("%d\n",dinic(0,n+1));
    }
    return 0;
}
