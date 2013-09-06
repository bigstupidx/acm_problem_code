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
    bool f1,f2;
}tree[202];
void solve(int rot)
{
    if(tree[rot].sons==0){
        tree[rot].s1=1;
        tree[rot].s2=0;
        return ;
    }
    int sum1=0,sum2=0;
    for(int i=0;i<tree[rot].sons;i++){
        int u=tree[rot].adj[i];
        solve(u);
        sum1+=tree[u].s2;
        if(tree[u].f2)tree[rot].f1=true;
        if(tree[u].s1>tree[u].s2)
            sum2+=tree[u].s1;
        else sum2+=tree[u].s2;
        if(tree[u].s1==tree[u].s2){
            tree[rot].f2=true;
        }
    }
    tree[rot].s1=sum1+1;
    tree[rot].s2=sum2;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int id=1;
        map<string,int>mp;
        map<string,int>::iterator p;
        for(int i=0;i<=n;i++){
            tree[i].sons=0;
            tree[i].s1=tree[i].s2=0;
            tree[i].f1=tree[i].f2=0;
        }
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
        int tem=tree[1].s2>tree[1].s1?tree[1].s2:tree[1].s1;
        printf("%d ",tem);
        if(tree[1].f1||tree[1].f2)
            puts("Yes");
        else puts("No");
    }
    return 0;
}
