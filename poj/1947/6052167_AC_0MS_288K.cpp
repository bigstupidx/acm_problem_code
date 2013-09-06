#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct node{
    int ss[160];
    vector<int>adj;
}nod[160];
int mini,n,p,par[160];
const int inf = 1000000000;
void init()
{
    mini=inf;
    for(int i=1;i<=n;i++){
        nod[i].adj.clear();
        nod[i].ss[0]=1;nod[i].ss[1]=0;
        for(int j=2;j<=n;j++)
            nod[i].ss[j]=inf;
    }
    memset(par,-1,sizeof(par));
}
void DFS(int s)
{
    for(int i=0;i<nod[s].adj.size();i++)
    {
        int u=nod[s].adj[i];
        DFS(u);
        for(int j=n;j>0;j--)
        {
            nod[s].ss[j]++;
            for(int k=0;k<j;k++)
                if(nod[s].ss[j]>nod[s].ss[j-k]+nod[u].ss[k])
                    nod[s].ss[j]=nod[s].ss[j-k]+nod[u].ss[k];
        }
    }
    if(nod[s].ss[p]+1<mini)mini=nod[s].ss[p]+1;
}
int main()
{
    while(scanf("%d%d",&n,&p)!=EOF)
    {
        init();
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            par[y]=x;
            nod[x].adj.push_back(y);
        }
        int root;
        for(int i=1;i<=n;i++)
            if(par[i]==-1){root=i;break;}
        DFS(root);
        if(nod[root].ss[p]<mini)mini=nod[root].ss[p];
        printf("%d\n",mini);
    }
    return 0;
}
