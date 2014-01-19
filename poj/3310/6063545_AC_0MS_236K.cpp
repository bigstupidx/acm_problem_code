#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
int n,m,map[120][120],deg[120],visit[120];
bool DFS(int s,int fa)
{
    visit[s]=1;
    for(int i=1;i<=n;i++)
    {
        if(map[s][i])
        {
            if(i==fa)continue;
            if(visit[i])return false;
            if(!DFS(i,s))return false;
        }
    }
    return true;
}
int main()
{
    int t=0;
    while(scanf("%d",&n),n)
    {
        t++;
        scanf("%d",&m);
        memset(deg,0,sizeof(deg));
        memset(map,0,sizeof(map));
        int flag=0;
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(flag)continue;
            if(x==y)flag=1;
            if(map[x][y])continue;
            deg[x]++;   deg[y]++;
            map[x][y]=map[y][x]=1;
        }
        if(flag){
            printf("Graph %d is not a caterpillar.\n",t);
            continue;
        }
        memset(visit,0,sizeof(visit));
        if(!DFS(1,1)){
            printf("Graph %d is not a caterpillar.\n",t);
            continue;
        }
        for(int i=1;i<=n;i++)
            if(!visit[i]){flag=1;break;}
        if(flag)printf("Graph %d is not a caterpillar.\n",t);
        else{
            int cnt=0;
            stack<int>S;
            memset(visit,0,sizeof(visit));
            for(int i=1;i<=n;i++)
                if(deg[i]==1){S.push(i);visit[i]=1;}
            while(!S.empty())
            {
                int i=S.top();S.pop();
                for(int j=1;j<=n;j++)
                    if(map[i][j])
                        deg[j]--;
            }
            for(int i=1;i<=n;i++)
                if(!visit[i]&&deg[i]==1)cnt++;
            //printf("%d ",cnt);
            if(cnt<=2)printf("Graph %d is a caterpillar.\n",t);
            else printf("Graph %d is not a caterpillar.\n",t);
        }
    }
    return 0;
}
