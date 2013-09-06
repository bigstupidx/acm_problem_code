#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>

#define MAXN 30010
#define MAXM 150010

using namespace std;

int N,M;

int value[MAXN];

struct Edge{

	   int u,v,next;

};
Edge mm[MAXM],gg[MAXM],MM[MAXM];
int adj[MAXN],adj2[MAXN],adj3[MAXN];
int pos,pos2,pos3;
int vis[MAXN];
int st[MAXN];
int cnt;
int scc[MAXN];
int dist[MAXN];

void AddEdge(int a,int b)// 正向 
{
  mm[pos].u = a;	
  mm[pos].v = b;
  mm[pos].next = adj[a];
  adj[a] = pos++; 
}
void addedge(int a,int b)
{
  gg[pos2].u = a;	
  gg[pos2].v = b;
  gg[pos2].next = adj2[a];
  adj2[a] = pos2++;  
}
void Add_Edge(int a,int b)
{
  	 MM[pos3].u = a;
	 MM[pos3].v = b;
	 MM[pos3].next = adj3[a];
	 adj3[a] = pos3++;
}
void dfsr(int i)
{
 	vis[i] = 1;
	for(int j= adj2[i];j!=-1;j=gg[j].next)
	{
	 	if(!vis[gg[j].v])
		{
		 	dfsr(gg[j].v);
		}
	}
	st[cnt++] =i;
}
void dfs(int i)
{
	vis[i] = 1;
	scc[i] = cnt;
	for(int j= adj[i];j!=-1;j=mm[j].next)
	{
	 	if(!vis[mm[j].v])
		{
		 	dfs(mm[j].v);
		}
	}	 
}
int ans[MAXN];
int du[MAXN];

int f(int i)
{
	if(ans[i]!=-1)return ans[i];
	ans[i]=dist[i];
	for(int j=adj3[i];j!=-1;j=MM[j].next)
	{
		f(MM[j].v);
		ans[i]=max(ans[i],ans[MM[j].v]+dist[i]);
	}

	return ans[i];
}
int main(){


	while(scanf("%d %d",&N,&M)!=EOF)
	{
		for(int i =0;i<N ;i ++){
				
				adj[i] = -1;
				adj2[i]= -1;
				adj3[i] = -1;
		}
		memset(value,0,sizeof(value));
		for(int i =0;i <N; i++)
		{
		 	scanf("%d",&value[i]);
			if(value[i]<0)value[i] = 0;
		}
		pos = pos2 = pos3 = 0;
		for(int i =0;i<M; i++)
		{
		 	int a,b;
			scanf("%d %d",&a,&b);
			AddEdge(a,b);
			addedge(b,a);
		}
		cnt = 0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<N; i++)
		{
		 	if(!vis[i])
			dfsr(i);
		}
		cnt= 0;
		memset(vis,0,sizeof(vis));
		for(int i =N -1;i>=0;i--)
		{
		 	if(!vis[ st[i] ])
			{
			 	dfs(st[i]);
				cnt++;
			}
		}
		memset(dist,0,sizeof(dist));
		for(int i =0 ;i<N; i++)dist[scc[i]]+=value[i];
		memset(du,0,sizeof(du));
		for(int i =0 ;i<N; i++)
		{
		 	int sum = 0;
		 	for(int j =adj[i];j!=-1;j=mm[j].next)
			{
			 	int u = scc[i];
				int v = scc[mm[j].v];
				if(u!=v)
				{
				 	du[v]++;
				 	Add_Edge(u,v);
				}
			}
		}
		for(int i= 0;i<cnt; i++)ans[i]=-1;
		//printf("%d\n",f(scc[0]));//错在这里，可以从别的地方出发
        ///*
        int maxi=-1;
        for(int i=0;i<cnt;i++){
            if(du[i]==0){
                int tem=f(i);
                if(maxi<tem)
                    maxi=tem;
            }
        }
        printf("%d\n",maxi);
        //*/ 
	}

	return 0;
}
