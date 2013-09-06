#include <stack>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int ing[120],n;
vector<int>adj[120],ans;
void topsort()
{
    stack<int>Q;
    for(int i=1;i<=n;i++)
        if(ing[i]==0)Q.push(i);
    while(!Q.empty())
    {
        int u=Q.top();Q.pop();
        ans.push_back(u);
        for(int i=0;i<adj[u].size();i++)
        {
            ing[adj[u][i]]--;
            if(ing[adj[u][i]]==0)Q.push(adj[u][i]);
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int u;
        memset(ing,0,sizeof(ing));
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            while(scanf("%d",&u),u){
                ing[u]++;
                adj[i].push_back(u);
            }
        }
        topsort();
        for(int i=0;i<n;i++)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
