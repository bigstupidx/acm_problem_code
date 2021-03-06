#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
struct adjvert{
    map<pair<int,int>,int>mp;
}adj[50];
int n,deg[50];
vector<int>ans;
map<pair<int,int>,int>::iterator p,q;
void DFS(int s)
{
    if(adj[s].mp.empty())return ;
    for(p=adj[s].mp.begin();;p++)
    {
        int t=(p->first).second;
        int nn=(p->first).first;
        ans.push_back(nn);
        q=adj[t].mp.find(make_pair(nn,s));
        adj[t].mp.erase(q);
        adj[s].mp.erase(p);
        DFS(t);
        if(adj[s].mp.empty())break;
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
            adj[i].mp.clear();
        scanf("%d",&num);
        adj[s].mp.insert(make_pair(make_pair(num,t),1));
        adj[t].mp.insert(make_pair(make_pair(num,s),1));
        while(scanf("%d%d",&s,&t),s||t)
        {
            deg[s]++;deg[t]++;
            if(s>n)n=s;if(t>n)n=t;
            scanf("%d",&num);
            adj[s].mp.insert(make_pair(make_pair(num,t),1));
            adj[t].mp.insert(make_pair(make_pair(num,s),1));
        }
        for(i=1;i<=n;i++)
            if(deg[i]%2)break;
        if(i<=n){
            puts("Round trip does not exist.");
            continue;
        }
        ans.clear();
        DFS(ss);
        for(i=0;i<ans.size();i++)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
