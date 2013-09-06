#include<stdio.h>
using namespace std;
const int Len=100005;
#define max(a,b) (a>b?a:b)
struct node{
       int degr;
       int numC;
       int tt;
       int next[105];
}T[Len];
__int64 dp[Len];
bool f[Len], ff[Len];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;++i)
        {
            T[i].numC=T[i].degr=0;  //入度和初度 
            f[i]=true;   //标记初度 
            ff[i]=true;  //标记入度 
            int nt;
            scanf("%d",&nt);
            T[i].tt=nt;
        }
        for(int j=1;j<=m;++j)
        {
             int s,e;
             scanf("%d%d",&s,&e);
             T[s].next[++T[s].numC]=e;
             f[s]=false;
             ff[e]=false;
             ++T[e].degr;
        }
        for(int i=1;i<=n;++i)
            if(ff[i]) dp[i]=T[i].tt;
            else dp[i]=-2000000001;
        int stack[Len];
        int top;
        int tnum;
        tnum=0;
        top=0;
        for(int i=1;i<=n;++i)
            if(T[i].degr==0)
            {
                ++tnum;
                stack[++top]=i;
            }
        while(top)
        {
             int temp=stack[top--];
             for(int i=1;i<=T[temp].numC;++i)
             {
                  T[T[temp].next[i]].degr--;
                  if(T[T[temp].next[i]].degr==0)
                       stack[++top]=T[temp].next[i];
                  dp[T[temp].next[i]]=max(dp[T[temp].next[i]],T[T[temp].next[i]].tt+dp[temp]);
             }
        }
        __int64 ans=-2000000001;
        for(int i=1;i<=n;++i)
           if(f[i]) ans=max(dp[i],ans);
        printf("%I64d\n",ans);
    }
    return 0;
}
