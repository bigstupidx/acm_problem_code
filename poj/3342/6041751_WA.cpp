#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
char aa[120],bb[120];
struct Tnode{
    int sons;
    int adj[202];
    int s1,s2;//s1表示选，s2表示不选 
}tree[202];
int n;
inline int Max(int x,int y){return x>y?x:y;}
void solve(int rot)
{
    if(tree[rot].sons==0){
        tree[rot].s1=1;
        tree[rot].s2=0;
        return ;
    }
    int sum1=0,sum2=0;
    for(int i=0;i<tree[rot].sons;i++){
        if(tree[tree[rot].adj[i]].s1!=0){
            sum1+=tree[tree[rot].adj[i]].s2;
            sum2+=tree[tree[rot].adj[i]].s1;
            continue;
        }
        solve(tree[rot].adj[i]);
        sum1+=tree[tree[rot].adj[i]].s2;
        sum2+=tree[tree[rot].adj[i]].s1;
    }
    tree[rot].s1=sum1+1;
    tree[rot].s2=sum2;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        int id=1;
        map<string,int>mp;
        map<string,int>::iterator p;
        for(int i=0;i<=n;i++){tree[i].sons=0;tree[i].s1=tree[i].s2=0;}
        scanf("%s",aa);
        mp[aa]=id++;
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%s%s",aa,bb);
            p=mp.find(aa);
            if(p==mp.end()){
                mp[aa]=id;
                u=id++;
            }
            else u=p->second;
            p=mp.find(bb);
            if(p==mp.end()){
                mp[bb]=id;
                v=id++;
            }
            else v=p->second;
            tree[v].adj[tree[v].sons++]=u;
        }
        solve(1);
        int cnt=0,tem=-1;
        for(int i=1;i<=n;i++){
            if(tree[i].s1>tem)tem=tree[i].s1;
            if(tree[i].s2>tem)tem=tree[i].s2;
        }
        //for(int i=1;i<=n;i++)
        //    printf("%d %d\n",tree[i].s1,tree[i].s2);
        printf("%d ",tem);
        for(int i=1;i<=n;i++){
            if(tree[i].s1==tem)cnt++;
            if(tree[i].s2==tem)cnt++;
        }
        if(cnt==1)puts("Yes");
        else puts("No");
    }
    return 0;
}
