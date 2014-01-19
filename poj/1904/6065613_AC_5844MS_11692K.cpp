#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int>front[4004],back[4004],ans;
int n,top,order[4004],id[4004],visit[4004],mat[2002][2002];
void DFS(int s)
{
    visit[s]=1;
    for(int i=0;i<front[s].size();i++)
        if(!visit[front[s][i]])
            DFS(front[s][i]);
    order[top++]=s;
}
void DFS_RG(int s)
{
    visit[s]=1;
    id[s]=top;
    for(int i=0;i<back[s].size();i++)
        if(!visit[back[s][i]])
            DFS_RG(back[s][i]);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=2*n;i++)front[i].clear(),back[i].clear();
        for(int i=1;i<=n;i++)
        {
            int m,u;
            scanf("%d",&m);
            mat[i][0]=m;
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&u);
                mat[i][j]=u+n;
                front[i].push_back(u+n);
                back[u+n].push_back(i);
            }
        }
        for(int i=1;i<=n;i++)
        {
            int u;
            scanf("%d",&u);
            front[u+n].push_back(i);
            back[i].push_back(u+n);
        }
        top=0;
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=2*n;i++)
            if(!visit[i])DFS(i);
        
        top=0;
        memset(visit,0,sizeof(visit));
        for(int i=2*n-1;i>=0;i--)
        {
            if(!visit[order[i]])
            {
                DFS_RG(order[i]);
                top++;
            }
        }
        /*
        for(int i=1;i<=2*n;i++)
            printf("%d ",id[i]);
        puts("");
        */ 
        for(int i=1;i<=n;i++)
        {
            ans.clear();
            for(int j=1;j<=mat[i][0];j++)
                if(id[mat[i][j]]==id[i])
                    ans.push_back(mat[i][j]-n);
            sort(ans.begin(),ans.end());
            printf("%d",ans.size());
            for(int j=0;j<ans.size();j++)
                printf(" %d",ans[j]);
            puts("");
        }
    }
    return 0;
}
