#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct strr{
    char str[22];
}sttr[1010];
struct adjv{
    int cnt;
    struct node{
        int nn, to;
        bool operator<(const node a)const
        {
            return a.nn>nn;
        }
    }nod[1010];
}adj[30];
int n,top,deg[30],flag[1010],ans[1010];
bool cmps(strr a,strr b){ return strcmp(a.str,b.str)<0; }
void DFS(int s)
{
    for(int i=0;i<adj[s].cnt;i++)
    {
        int nn=adj[s].nod[i].nn;
        if(!flag[nn])
        {
            flag[nn]=1;
            DFS(adj[s].nod[i].to);
            ans[top--]=nn;
        }
    }
}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--)
    {
        int ss,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",sttr[i].str);
        sort(sttr,sttr+n,cmps);
        for(i=0;i<30;i++)adj[i].cnt=0;
        memset(deg,0,sizeof(deg));
        for(i=0;i<n;i++)
        {
            int len=strlen(sttr[i].str);
            int s=sttr[i].str[0]-'a';
            int t=sttr[i].str[len-1]-'a';
            //printf("%d %d\n",s,t);
            deg[s]++;   deg[t]++;
            adj[s].nod[adj[s].cnt].nn=i;adj[s].nod[adj[s].cnt++].to=t;
            adj[t].nod[adj[t].cnt].nn=i;adj[t].nod[adj[t].cnt++].to=s;
        }
        for(i=0;i<30;i++)
            sort(adj[i].nod,adj[i].nod+adj[i].cnt);
        int cnt=0;
        for(i=0;i<30;i++)
            if(deg[i]%2){
                cnt++;
                if(cnt==1)ss=i;
            }
        if(cnt!=2){
            puts("***");
            continue;
        }
        memset(flag,0,sizeof(flag));
        top=n;DFS(ss);
        if(top!=0)puts("***");
        else{
            printf("%s",sttr[ans[1]].str);
            for(i=2;i<=n;i++)
                printf(".%s",sttr[ans[i]].str);
            puts("");
        }
    }
    return 0;
}
