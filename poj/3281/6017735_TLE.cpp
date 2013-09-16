#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
int c[400][400],n,f,d,s,t,pre[400];
const int inf = 1000000000;
int Max_Flow()
{
    int flow=0;
    while(1)
    {
        int i,mini=inf;
        queue<int>Q;
        memset(pre,-1,sizeof(pre));
        Q.push(s);
        while(!Q.empty()&&pre[t]==-1)
        {
            i=Q.front();Q.pop();
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
        for(i=t;i!=s;i=pre[i])
            if(mini>c[pre[i]][i])mini=c[pre[i]][i];
        flow+=mini;
        for(i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&f,&d)!=EOF)
    {
        int m1,m2,x;
        s=0;    t=2*n+f+d+1;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&m1,&m2);
            for(int j=1;j<=m1;j++)
            {
                scanf("%d",&x);
                c[x][2*i+f-1]=1;
            }
            for(int j=1;j<=m2;j++)
            {
                scanf("%d",&x);
                c[2*i+f][x+f+2*n]=1;
            }
        }
        for(int i=1;i<=n;i++)c[2*i-1+f][2*i+f]=1;
        for(int i=1;i<=f;i++)c[0][i]=1;
        for(int i=1;i<=d;i++)c[i+2*n+f][t]=1;
        printf("%d\n",Max_Flow());
    }
    return 0;
}
