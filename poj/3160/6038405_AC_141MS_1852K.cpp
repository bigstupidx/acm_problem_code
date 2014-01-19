#include <cstdio>
#include <vector>
#include <cstring>
#define M 30010
#define Max(a,b) (a>b?a:b)
using namespace std;
vector<int>front[M],back[M];
int n,m,wi[M],order[M],id[M],visit[M],top;
int va[M],in[M],ans[M];
void DFS(int s)
{
    visit[s]=1;
    for(int i=0;i<front[s].size();i++)
        if(!visit[front[s][i]])DFS(front[s][i]);
    order[top++]=s;
}
void DFS_RG(int s)
{
    visit[s]=1;
    id[s]=top;
    for(int i=0;i<back[s].size();i++)
        if(!visit[back[s][i]])DFS_RG(back[s][i]);
}
bool v[M];

int DP(int x)
{
    if(v[x]) return ans[x];
    int maxback = 0;
    for(int i = 0;i<front[x].size();++i){
        int tp = DP(front[x][i]);
        maxback = Max(maxback,tp);
    }
    ans[x] = va[x] + maxback;
    return ans[x] ;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++){front[i].clear();back[i].clear();}
        for(int i=1;i<=n;i++)
            scanf("%d",wi+i);
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++;    y++;
            front[x].push_back(y);
            back[y].push_back(x);
        }
        top=1;
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=n;i++)
            if(!visit[i])DFS(i);
        top=1;
        memset(visit,0,sizeof(visit));
        for(int i=n;i>0;i--)
            if(!visit[order[i]]){DFS_RG(order[i]);top++;}
        for(int i=1;i<top;i++)front[i].clear();
        
        memset(in,0,sizeof(in));
        for(int i=1;i<=n;i++)
            for(int j=0;j<back[i].size();j++)
                if(id[i]!=id[back[i][j]]){
                    front[id[back[i][j]]].push_back(id[i]);
                    in[id[i]]++;
                }
        memset(va,0,sizeof(va));
        for(int i=1;i<=n;i++)if(wi[i]>0)va[id[i]]+=wi[i];
        n=top-1;
        int maxv = 0;
        memset(v,0,sizeof(v));
        for(int i =1;i<=n;i++)
        if(! in[i]){
            int tp = DP(i);
            maxv = Max(maxv,tp);
        }
        printf("%d\n",maxv);
    }
    system("pause");
    return 0;
}
