#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n,m,in[220],out[220],c[220][220],pre[220];
const int inf = 1000000000;
int Max_Flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        int mini=inf;
        queue<int>Q;
        memset(pre,-1,sizeof(pre));
        Q.push(s);
        while(!Q.empty()&&pre[t]==-1)
        {
            int i=Q.front();Q.pop();
            for(int j=0;j<=t;j++)
            {
                if(pre[j]==-1&&c[i][j]>0)
                {
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1)return flow;
        for(int i=t;i!=s;i=pre[i])
            if(mini>c[pre[i]][i])mini=c[pre[i]][i];
        flow+=mini;
        for(int i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
    }
}
bool solve()
{
    memset(c,0,sizeof(c));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(int i=1;i<=m;i++){
        int x,y,tag;
        scanf("%d%d%d",&x,&y,&tag);
        in[y]++;    out[x]++;
        if(tag==0)c[x][y]+=1;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int k=out[i]-in[i];
        if(k%2==1)return false;
        k/=2;
        if(k<0)c[i][n+1]=-k;
        else{
            sum+=k;
            c[0][i]=k;
        }
    }
    return sum==Max_Flow(0,n+1);
}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--){
        scanf("%d%d",&n,&m);
        if(solve())puts("possible");
        else puts("impossible");
    }
    system("pause");
    return 0;
}
