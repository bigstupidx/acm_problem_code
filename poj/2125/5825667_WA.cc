#include<queue>
#include<cstdio>
#include<cstring>
#define inf 1000000000
using namespace std;

int pre[250],c[250][250],n,flag[250],e[5005][2];
int Max_Flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        int mini=inf,i;
        queue<int>Q;
        Q.push(s);
        memset(pre,-1,sizeof(pre));
        while(!Q.empty()&&pre[t]==-1)
        {
            i=Q.front();Q.pop();
            for(int j=1;j<=t;j++)
                if(pre[j]==-1&&c[i][j]>0)
                {
                    pre[j]=i;
                    Q.push(j);
                }
        }
        if(pre[t]==-1)return flow;
        for(i=t;i!=s;i=pre[i])
            if(mini>c[pre[i]][i])mini=c[pre[i]][i];
        for(i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
        flow+=mini;
    }
}
void DFS(int s)
{
    flag[s]=1;
    for(int i=1;i<=2*n;i++)
        if(!flag[i]&&c[s][i]>0)
            DFS(i);
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
            scanf("%d",&c[0][i]);
        for(int i=n+1;i<=2*n;i++)
            scanf("%d",&c[i][2*n+1]);
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            e[i][0]=x;  e[i][1]=y;
            c[y][n+x]=inf;
        }
        printf("%d\n",Max_Flow(0,2*n+1));
        int cnt=0;
        memset(flag,0,sizeof(flag));
        for(int i=1;i<=n;i++)
            if(c[0][i]==0){flag[i]=1;cnt++;}
        for(int i=n+1;i<=2*n;i++)
            if(c[i][2*n+1]==0){flag[i]=1;cnt++;}
        printf("%d\n",cnt);
        for(int i=1;i<=2*n;i++)
            if(flag[i]&&i<=n)printf("%d +\n",i);
            else if(flag[i]&&i>n)printf("%d -\n",i-n);
    }
    return 0;
}
