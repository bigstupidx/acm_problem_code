#include<cstdio>
using namespace std;
const int Len=100005;
#define max(a,b) (a>b?a:b)
struct node{
       int degr;
       int numC;
       int tt;
       int next[105];
}T[Len];
long long dp[Len];
void DFS(int s)
{
    if(dp[s]!=-2000000001)
        return ;
    dp[s]=T[s].tt;
    long long maxi=-2000000001;
    for(int j=1;j<=T[s].numC;j++){
        DFS(T[s].next[j]);
        if(maxi<dp[T[s].next[j]])
            maxi=dp[T[s].next[j]];
    }
    if(maxi==-2000000001)maxi=0;
    dp[s] += maxi;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;++i)
        {
            T[i].numC=T[i].degr=0;  //入度和初度 
            int nt;
            scanf("%d",&nt);
            T[i].tt=nt;
        }
        for(int j=1;j<=m;++j)
        {
             int s,e;
             scanf("%d%d",&s,&e);
             T[s].next[++T[s].numC]=e;
             ++T[e].degr;
        }
        for(int i=1;i<=n;++i)
            dp[i]=-2000000001;
        for(int i=1;i<=n;i++){
            if(T[i].degr==0)DFS(i);
        }
        long long ans=-2000000001;
        for(int i=1;i<=n;++i)
           if(T[i].degr==0) ans=max(dp[i],ans);
        printf("%lld\n",ans);
    }
    return 0;
}
