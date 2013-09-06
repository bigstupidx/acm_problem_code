#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <map>
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
    }nod[2000];
}adj[50];
int n,m,deg[50],flag[2002],ans[2002],top;
bool DFS(int s,int cnt)
{
    if(cnt==m)return true;
    for(int i=0;i<adj[s].cnt;i++)
    {
        int t=adj[s].nod[i].to;
        int nn=adj[s].nod[i].nn;
        if(!flag[nn])
        {
           // printf("%d %d %d\n",s,p->second,p->first);
            flag[nn]=1;
            if(DFS(t,cnt+1))
            {
                ans[top--]=nn;
                return true;
            }
            flag[nn]=0;
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
            adj[i].cnt=0;
        scanf("%d",&num);
        adj[s].nod[adj[s].cnt].nn=num;    adj[s].nod[adj[s].cnt++].to=t;
        adj[t].nod[adj[t].cnt].nn=num;    adj[t].nod[adj[t].cnt++].to=s;
        while(scanf("%d%d",&s,&t),s||t)
        {
            deg[s]++;deg[t]++;m++;
            if(s>n)n=s; if(t>n)n=t;
            scanf("%d",&num);
            adj[s].nod[adj[s].cnt].nn=num;adj[s].nod[adj[s].cnt++].to=t;
            adj[t].nod[adj[t].cnt].nn=num;adj[t].nod[adj[t].cnt++].to=s;
        }
        for(i=1;i<=n;i++)
            if(deg[i]%2)break;
        if(i<=n){
            puts("Round trip does not exist.");
            continue;
        }
        for(i=1;i<=n;i++)
            sort(adj[i].nod,adj[i].nod+adj[i].cnt);
        /*for(i=1;i<=n;i++)
            for(int j=0;j<adj[i].cnt;j++)
                printf("%d->%d %d\n",i,adj[i].nod[j].to,adj[i].nod[j].nn);
        */
        memset(flag,0,sizeof(flag));
        top=m;  DFS(ss,0);
        for(i=1;i<=m;i++)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
