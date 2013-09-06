#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
struct adjv{
    map<int,int>mp;
}adj[50];
int n,deg[50],flag[2002];
vector<int>ans;
void DFS(int s)
{
    stack<int>S;
    S.push(s);
    map<int,int>::iterator p;
    memset(flag,0,sizeof(flag));
    while(!S.empty()){
        s=S.top();S.pop();
        for(p=adj[s].mp.begin();p!=adj[s].mp.end();p++)
        {
            if(!flag[p->first])
            {
                ans.push_back(p->first);
                flag[p->first]=1;
                S.push(p->second);
                break;
            }
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
            adj[i].mp.clear();
        scanf("%d",&num);
        adj[s].mp.insert(make_pair(num,t));
        adj[t].mp.insert(make_pair(num,s));
        while(scanf("%d%d",&s,&t),s||t)
        {
            deg[s]++;deg[t]++;
            if(s>n)n=s; if(t>n)n=t;
            scanf("%d",&num);
            adj[s].mp.insert(make_pair(num,t));
            adj[t].mp.insert(make_pair(num,s));
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
