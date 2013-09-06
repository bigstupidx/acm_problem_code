#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int size=105,inf=0x7fffffff;

typedef struct Path
{
    int v,w;
    int b,e;
}Path;

typedef struct Data
{
    int v;
    int time;
}Data;

bool operator < (Data a,Data b)
{
    return a.time>b.time;
}

priority_queue<Data>Q;
vector<Path> path[size];
int N,M;
bool use[size];

int Max(int a,int b) {return a>b?a:b;}

int BFS(int s,int t,int j)
{
    int v,i;
    while(!Q.empty()) Q.pop();
    memset(use,false,sizeof(use));
    Data q,np;
    q.time=j;
    q.v=s;
    Q.push(q);
    while(!Q.empty())
    {
        q=Q.top();  Q.pop();
        if(use[q.v]) continue;
        use[q.v]=true;
        v=q.v;
        if(v==t) return q.time-j;
        for(i=0;i<path[v].size();i++)
            if(!use[path[v][i].v])
            {
                np.time=Max(q.time,path[v][i].b)+path[v][i].w;
                np.v=path[v][i].v;
                if(np.time<=path[v][i].e) 
                    Q.push(np);
            }
    }
    return inf;
}
int Slove(int s,int t)
{
    int i,min=inf,len=0,temp;
    for(i=0,len=0;i<path[s].size();i++)
    {
        if(len<path[s][i].e) len=path[s][i].e;
    }
    for(i=0;i<=len;i++)
    {
        temp=BFS(s,t,i);
        if(temp<min) min=temp;
    }
    return min;
}
int main()
{
    int s,t,i;
    int u;
    Path q;
    scanf("%d%d%d%d",&N,&M,&s,&t);
    while(M--)
    {
        scanf("%d%d%d%d%d",&u,&q.v,&q.b,&q.e,&q.w);
        path[u].push_back(q);
    }
    i=Slove(s,t);
    if(i==inf) printf("Impossible\n");
    else printf("%d\n",i);
    return 12;
}
