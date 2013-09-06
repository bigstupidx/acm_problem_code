#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
#define min(a,b) a<b?a:b
vector<int>node[2050];
int a[2050],b[2050],opp[2050],id[2050],dfn[2050],stack[2050],low[2050];
bool use[2050],instack[2050];
int num,gcc,n,m;
void dfs(int u)
{
	int i,v;
	num++;
	use[u] = 1;
	stack[num] = u;
	instack[u] = 1;
	dfn[u] = low[u] = num;
	for(i = 0;i < node[u].size();i++)
	{
		if(!use[node[u][i]])
		{
			dfs(node[u][i]);
			low[u] = min(low[u],low[node[u][i]]);
		}
		else
		{
			if(instack[node[u][i]])
			{
				low[u] = min(low[u],dfn[node[u][i]]);
			}
		}
	}
	if(dfn[u] == low[u])
	{
		gcc++;
		do
		{
			v = stack[num--];
			instack[v] = 0;
			id[v] = gcc;
		}while(v != u);
	}
}
void trajan(int ans)
{
	int i;
	for(i = 1;i <= 2*n;i++)
		node[i].clear();
	
    for(i = 1;i <= ans;i++)
	{
		node[a[i]].push_back(opp[b[i]]);
		node[b[i]].push_back(opp[a[i]]);
	}
	
	memset(use,0,sizeof(use));
	memset(instack,0,sizeof(instack));
	num = 0;
	gcc = 0;
	for(i = 1;i <= 2*n;i++)
		if(!use[i])
			dfs(i);
}
bool check()
{
	int i;
	for(i = 1;i <= 2*n;i++)
		if(id[i] == id[opp[i]])
		    	return 0;
	return 1;
}
void solve()
{
	int i;
	int left = 0;
	int right = m + 1;
	int mid;
	while(left <= right)
	{
		mid = (left + right)/2;
		//printf("Try left mid right:  %d %d %d\n",left,mid,right);
		trajan(mid);
		if(check())
			left = mid + 1;
		else
			right = mid - 1;
	}
	printf("%d\n",left-1);
	/*for(i = 1;i <= m;i++)
	{
		node[a[i]].push_back(node[b[i]]);
		node[b[i]].push_back(node[a[i]]);
		trajan();
		if(!check())
		{
			printf("%d\n",i - 1);
			return ;
		}
	}*/
	//printf("%d\n",n);
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
