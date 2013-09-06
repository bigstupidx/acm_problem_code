#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
struct adjv{
    int cnt;
    struct node{
        int nn;
        int to;
        bool operator<(const node a)const
        {
            return a.nn>nn;
        }
    }nod[2002];
}adj[50];
int n,deg[50],flag[2002];
vector<int>ans;
void DFS(int s)
{
    stack<int>S;
    S.push(s);
    memset(flag,0,sizeof(flag));
    while(!S.empty()){
        s=S.top();S.pop();
        for(int i=0;i<adj[s].cnt;i++)
            if(!flag[adj[s].nod[i].nn])
            {
                ans.push_back(adj[s].nod[i].nn);
                flag[adj[s].nod[i].nn]=1;
                S.push(adj[s].nod[i].to);
                break;
            }
    }
    return ;
}
int main()
{
    int s,t;
    while(scanf("%d%d",&s,&t),s||t)
    {
        int i,ss,num;
        ss=s>t?t:s; n=s>t?s:t;
        memset(deg,0,sizeof(deg));
        deg[s]++;   deg[t]++;
        for(i=0;i<50;i++)
            adj[i].cnt=0;
        scanf("%d",&num);
        adj[s].nod[adj[s].cnt].nn=num; adj[s].nod[adj[s].cnt++].to=t;
        adj[t].nod[adj[t].cnt].nn=num; adj[t].nod[adj[t].cnt++].to=s;
        while(scanf("%d%d",&s,&t),s||t)
        {
            deg[s]++;deg[t]++;
            if(s>n)n=s; if(t>n)n=t;
            scanf("%d",&num);
           adj[s].nod[adj[s].cnt].nn=num; adj[s].nod[adj[s].cnt++].to=t;
           adj[t].nod[adj[t].cnt].nn=num; adj[t].nod[adj[t].cnt++].to=s;
        }
        for(i=1;i<=n;i++)
            if(deg[i]%2)break;
        if(i<=n){
            puts("Round trip does not exist.");
            continue;
        }
        for(int i=1;i<=n;i++)
            sort(adj[i].nod,adj[i].nod+adj[i].cnt);
        /*for(int i=1;i<=n;i++)
            for(int j=0;j<adj[i].cnt;j++)
                printf("%d->%d %d\n",i,adj[i].nod[j].to,adj[i].nod[j].nn);
        */
        ans.clear();
        DFS(ss);
        for(i=0;i<ans.size();i++)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
