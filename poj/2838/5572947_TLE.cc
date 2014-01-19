#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;
int map[1002][1002],n;
bool v[1002];
int bfs(int s,int t)
{
    queue<int>Q;
    memset(v,false,sizeof(v));
    Q.push(s);v[s]=true;
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        v[u]=true;
        if(u==t)return 1;
        for(int i=1;i<=n;i++)
        {
            if(!v[i]&&map[u][i])
                Q.push(i);
        }
    }
    return 0;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        char ch;
        int u,v,q;
        memset(map,0,sizeof(map));
        scanf("%d",&q);
        while(q--)
        {
            getchar();
            scanf("%c %d %d",&ch,&u,&v);
            if(ch=='Q')
            {
                if(bfs(u,v))puts("Y");
                else puts("N");
            }
            else if(ch=='D') map[u][v]=map[v][u]=0;
            else map[u][v]=map[v][u]=1;
        }
    }
    return 0;
}
