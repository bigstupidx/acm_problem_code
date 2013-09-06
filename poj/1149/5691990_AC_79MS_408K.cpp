
#include <cstdio>
#include <cstring>
#include <queue>
#define inf 1000000000
using namespace std;
int pre[120],c[120][120],w[1010],n,mp[1010][120];
bool v[1010];
int Max_Flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        int mini=inf,i;
        memset(pre,-1,sizeof(pre));
        queue<int>Q;
        Q.push(s);pre[s]=-2;
        while(!Q.empty()&&pre[t]==-1)
        {
            i=Q.front();Q.pop();
            for(int j=0;j<=n+1;j++)
            {
                if(pre[j]==-1&&c[i][j]>0)
                {
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1)return flow;
        for(i=t;i!=s;i=pre[i])
            if(c[pre[i]][i]<mini)mini=c[pre[i]][i];
        for(i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
        flow+=mini;
    }
}
int main()
{
    int m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int i,j;
        for(i=0;i<n+2;i++)
            for(j=0;j<n+2;j++)
                c[i][j]=0;
        for(i=1;i<=m;i++)
        {
            v[i]=0;
            mp[i][0]=0;
            scanf("%d",w+i);
        }
        for(i=1;i<=n;i++)
        {
            int len;
            scanf("%d",&len);
            while(len--)
            {
                scanf("%d",&j);
                mp[j][++mp[j][0]]=i;
                if(!v[j]){v[j]=1;c[0][i]+=w[j];}
                else{
                    for(int k=1;k<mp[j][0];k++)
                        c[mp[j][k]][i]=inf;
                }
            }
            scanf("%d",&len);
            c[i][n+1]=len;
        }
        printf("%d\n",Max_Flow(0,n+1));
    }
    return 0;
}