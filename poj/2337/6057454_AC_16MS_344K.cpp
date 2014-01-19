#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct strr{    char str[22];   }sttr[1010];
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
int n,top,in[30],out[30],flag[1010],ans[1010];
bool cmps(strr a,strr b){ return strcmp(a.str,b.str)<0; }
void DFS(int s)
{
    for(int i=0;i<adj[s].cnt;i++)
    {
        int  t=adj[s].nod[i].to;
        int nn=adj[s].nod[i].nn;
        if(!flag[nn])
        {
            flag[nn]=1;
            DFS(t);
            //printf("%d - > %d %d\n",s,t,nn);
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
        int ss=30,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",sttr[i].str);
        sort(sttr,sttr+n,cmps);
        for(i=0;i<30;i++)adj[i].cnt=0;
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(i=0;i<n;i++)
        {
            int len=strlen(sttr[i].str);
            int s=sttr[i].str[0]-'a';
            int t=sttr[i].str[len-1]-'a';
            //printf("%d %d %d\n",s,t,i);
            out[s]++;   in[t]++;
            if(ss>s)ss=s;
            adj[s].nod[adj[s].cnt].nn=i;
            adj[s].nod[adj[s].cnt++].to=t;
        }
        for(i=0;i<30;i++)
            sort(adj[i].nod,adj[i].nod+adj[i].cnt);
        int cnt1=0,s,t,cnt2=0,cnt=0;
        for(i=0;i<30;i++)
            if(in[i]!=out[i]){
                if(in[i]==out[i]+1){t=i;cnt1++;}
                else if(out[i]==in[i]+1){
                    s=i;cnt2++;
                }
                else cnt++;
            }
        if(cnt||cnt1>1||cnt2>1||cnt1!=cnt2){
            puts("***");
            continue;
        }
        if(cnt1==0)s=ss;
        memset(flag,0,sizeof(flag));
        top=n;  DFS(s);
        if(top!=0)puts("***");//不连同 
        else{
            printf("%s",sttr[ans[1]].str);
            for(i=2;i<=n;i++)
                printf(".%s",sttr[ans[i]].str);
            puts("");
        }
    }
    return 0;
}
