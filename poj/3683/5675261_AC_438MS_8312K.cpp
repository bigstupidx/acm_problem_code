#include <iostream>
#include <vector>

using namespace std;

const int size=2010;

struct Wedding
{
	int begain,end;
	int start,over;
}wed[size/2];

vector<int> path[size];
vector<int> Map[size];
int S[size],P[size],pre[size],tag[size],Deg[size],color[size];
int Q[size],Qtail,Qhead;
int scnt,ptop,stop,cnt;

inline void Init(int N)
{
	for(int i=0;i<N;i++)
	{
		path[i].clear();
		Map[i].clear();
		pre[i]=-1;
		tag[i]=-1;
		color[i]=1;
		Deg[i]=0;
	}
	scnt=cnt=stop=ptop=0;
}


bool Ok(int a,int b,int c,int d)
{
	if(d<=a || b<=c) return false;

	return true;
}
void Add(int i,int j)
{
	path[i].push_back(j);
}
void MakeMap(int N)
{
	int i,j,u,v;
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++)
		{
			u=i<<1;
			v=j<<1;
			if(Ok(wed[i].begain,wed[i].end,wed[j].begain,wed[j].end))
			{
				Add(u,v^1);
				Add(v,u^1);
			}
			if(Ok(wed[i].begain,wed[i].end,wed[j].start,wed[j].over))
			{
				Add(u,v);
				Add(v^1,u^1);
			}
			if(Ok(wed[i].start,wed[i].over,wed[j].begain,wed[j].end))
			{
				Add(v,u);
				Add(u^1,v^1);
			}
			if(Ok(wed[i].start,wed[i].over,wed[j].start,wed[j].over))
			{
				Add(u^1,v);
				Add(v^1,u);
			}
		}
}

void DFS(int u)
{
	pre[u]=cnt++;
	S[stop++]=u;
	P[ptop++]=u;
	int i,len=path[u].size();
	for(i=0;i<len;i++)
	{
		int v=path[u][i];
		if(pre[v]==-1) DFS(v);
		else if(tag[v]==-1) while(pre[P[ptop-1]]>pre[v]) ptop--;
	}
	if(P[ptop-1]==u) ptop--;
	else return ;
	do
		tag[S[--stop]]=scnt;
	while(S[stop]!=u);
	scnt++;
}
void Gabow(int N)
{
	for(int i=0;i<N;i++)
		if(tag[i]==-1) 
			DFS(i);
}
void Topo(int N)
{
	Qhead=Qtail=0;
	int i;
	for(i=0;i<scnt;i++)
		if(Deg[i]==0) Q[Qtail++]=i;
	while(Qhead<Qtail)
	{
		i=Q[Qhead++];
		int j,len=Map[i].size();
		for(j=0;j<len;j++)
		{
			Deg[Map[i][j]]--;
			if(Deg[Map[i][j]]==0) Q[Qtail++]=Map[i][j];
		}
	}
	for(i=0;i<Qtail;i++)
		if(color[Q[i]])
		{
			for(int j=0;j<N;j++)
			if(tag[j]==Q[i]) color[tag[j^1]]=0;
		}
		
}

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		int i,D,j;
		int Sh,Sm,Th,Tm;
		Init(N<<1);
		for(i=0;i<N;i++)
		{
			scanf("%d:%d %d:%d %d",&Sh,&Sm,&Th,&Tm,&D);
			wed[i].begain=Sh*60+Sm;
			wed[i].end=wed[i].begain+D;
			wed[i].over=Th*60+Tm;
			wed[i].start=wed[i].over-D;
		}
		MakeMap(N);
		Gabow(N<<1);
		for(i=0;i<N;i++)
			if(tag[i<<1]==tag[(i<<1)^1]) break;
		if(i!=N)
		{
			printf("NO\n");
			continue;
		}
		
        N=N<<1;
		for(i=0;i<N;i++)
		{
			int len=path[i].size();
			for(j=0;j<len;j++)
				if(tag[i]!=tag[path[i][j]])
				{
					Map[tag[path[i][j]]].push_back(tag[i]);
					Deg[tag[i]]++;
				}
		}
		
		Topo(N);
		printf("YES\n");
		for(i=0;i<N;i++)
		{
			if(color[tag[i]])
			{
				j=i>>1;
				if(i%2)
					printf("%02d:%02d %02d:%02d\n",wed[j].start/60,wed[j].start%60,wed[j].over/60,wed[j].over%60);
				else
					printf("%02d:%02d %02d:%02d\n",wed[j].begain/60,wed[j].begain%60,wed[j].end/60,wed[j].end%60);
			}
		}
	}
	return 0;
}
