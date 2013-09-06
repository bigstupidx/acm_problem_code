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
int n,m,deg[50],flag[2002],ans[2002],top;
bool DFS(int s,int cnt)
{
    if(cnt==m)return true;
    map<int,int>::iterator p,q;
    for(p=adj[s].mp.begin();p!=adj[s].mp.end();p++)
    {
        if(!flag[p->first])
        {
           // printf("%d %d %d\n",s,p->second,p->first);
            flag[p->first]=1;
            if(DFS(p->second,cnt+1)){
                q=adj[p->second].mp.find(p->first);
                adj[p->second].mp.erase(q);
                ans[top--]=p->first;
                return true;
            }
            flag[p->first]=0;
        }
    }
    return false;
}
int main()
{
    int s,t;
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&s,&t),s||t)
    {
        int i,ss,num;
        ss=s>t?t:s; n=s>t?s:t;m=1;
        memset(deg,0,sizeof(deg));
        deg[s]++;   deg[t]++;
        for(i=0;i<50;i++)
            adj[i].mp.clear();
        scanf("%d",&num);
        adj[s].mp.insert(make_pair(num,t));
        adj[t].mp.insert(make_pair(num,s));
        while(scanf("%d%d",&s,&t),s||t)
        {
            deg[s]++;deg[t]++;m++;
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
        memset(flag,0,sizeof(flag));
        top=m;  DFS(ss,0);
        for(i=1;i<=m;i++)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
