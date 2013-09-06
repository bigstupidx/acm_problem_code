
#include <cstdio>
#include <cstring>
#include<queue>
#define INF 1000000000
using namespace std;

int f[110][110],pre[110],n;
int Max_Flow(int s,int t)
{
    int ans=0;
    while(1)
    {
        int i,min=INF;
        queue<int>Q;
        memset(pre,-1,sizeof(pre));
        Q.push(s);pre[s]=-2;
        while(!Q.empty()&&pre[t]==-1)
        {
            i=Q.front();Q.pop();
            for(int j=1;j<=n+1;j++)
            {
                if(pre[j]==-1&&f[i][j]>0)
                {
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1)return ans;
        for(i=t;i!=s;i=pre[i])
            if(min>f[pre[i]][i])min=f[pre[i]][i];
        for(i=t;i!=s;i=pre[i])
        {
            f[pre[i]][i]-=min;
            f[i][pre[i]]+=min;
        }
        ans+=min;
    }
}
int main()
{
    int np,nc,m;
    while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
    {
        int u,v,z,i;
        memset(f,0,sizeof(f));
        for(i=0;i<m;i++){
            while(getchar()!='(');
            scanf("%d,%d)%d",&u,&v,&z);
            f[u+1][v+1]=z;
        }
        for(i=0;i<np;i++){
            while(getchar()!='(');
            scanf("%d)%d",&u,&z);
            f[0][u+1]=z;
        }
        for(i=0;i<nc;i++){
            while(getchar()!='(');
            scanf("%d)%d",&u,&z);
            f[u+1][n+1]=z;
        }
        printf("%d\n",Max_Flow(0,n+1));
    }
    return 0;
}
