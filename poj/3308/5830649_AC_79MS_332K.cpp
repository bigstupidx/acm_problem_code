#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#define inf 100000000
using namespace std;
int m,n,pre[120];
double c[120][120];
double Max_Flow(int s,int t)
{
    double flow=0;
    while(1)
    {
        double mini=1000000000;
        queue<int>Q;
        Q.push(s);
        memset(pre,-1,sizeof(pre));
        while(!Q.empty()&&pre[t]==-1)
        {
            int i=Q.front();Q.pop();
            for(int j=1;j<=t;j++)
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
        for(int i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
        flow+=mini;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l;
        double tem;
        scanf("%d%d%d",&m,&n,&l);
        memset(c,0,sizeof(c));
        for(int i=1;i<=m;i++){
            scanf("%lf",&tem);
            c[0][i]=log10(tem);
        }
        for(int i=m+1;i<=m+n;i++){
            scanf("%lf",&tem);
            c[i][n+m+1]=log10(tem);
        }
        for(int i=0;i<l;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            c[x][y+m]=inf;
        }
        printf("%.4lf\n",pow(10,Max_Flow(0,m+n+1)));
    }
    return 0;
}
