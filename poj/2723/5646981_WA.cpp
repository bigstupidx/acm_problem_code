#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
#define min(a,b) a<b?a:b
vector<int>node[2050];
vector<int>node1[2050];
int a[2050],b[2050],opp[2050],id[2050],dfn[2050],stack[2050],low[2050];
bool use[2050],instack[2050];
int num,gcc,n,m;

void dfs1(int u)
{
	int i;
	use[u] = 1;
	for(i = 0;i < node[u].size();i++)
		if(!use[node[u][i]])
			dfs1(node[u][i]);
	dfn[++num] = u;
}
void dfs2(int u)
{
	int i;
	use[u] = 1;
	id[u] = gcc;
	for(i = 0;i < node1[u].size();i++)
		if(!use[node1[u][i]])
			dfs2(node1[u][i]);
}
void kosaraju()
{
	int i;
	memset(use,0,sizeof(use));
	num = 0;
	for(i = 1;i <= 2*n;i++)
		if(!use[i])
			dfs1(i);
	memset(use,0,sizeof(use));
	gcc = 0;
	for(i = num;i >= 1;i--)
	{
		if(!use[dfn[i]])
		{
			gcc++;
			dfs2(dfn[i]);
		}
	}
}
bool check()
{
	int i;
	for(i = 1;i <= 2*n;i++)
		if(id[i] == id[opp[i]])
		    	return 0;
	return 1;
}

void my_clear(int mid)
{
	for(int i=1;i<=2*n;i++)
	   node[i].clear();
	for(int i = 1;i <= mid;i++)
	{
		node[a[i]].push_back(opp[b[i]]);
		node[b[i]].push_back(opp[a[i]]);
		node1[opp[b[i]]].push_back(a[i]);
		node1[opp[a[i]]].push_back(b[i]);
    }
    return ;
}
void solve()
{
    int l=1,r=m,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        my_clear(mid);
        kosaraju();
        if(check())
            l=mid+1;
        else 
            r=mid-1;
    }
    printf("%d\n",r);
}
int main()
{
	int i,a1,b1;
	while(scanf("%d%d",&n,&m) != EOF && n + m)
	{
		for(i = 1;i <= n;i++)
		{
			scanf("%d%d",&a1,&b1);
			a1++;
			b1++;
			opp[a1] = b1;
			opp[b1] = a1;
		}
		for(i = 1;i <= m;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			a[i]++;
			b[i]++;
		}
		solve();
	}
	return 0;
}
