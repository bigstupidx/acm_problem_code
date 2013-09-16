#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000
using namespace std;
int map[240][240],dp[240][240],f[240][240];
int k,c,m,pre[240];

void Short_Path_Floyd()
{
    for(int i=1;i<=k+c;i++)
        for(int j=1;j<=k+c;j++)
            dp[i][j]=map[i][j];
    for(int u=1;u<=k+c;u++)
        for(int v=1;v<=k+c;v++)
            for(int w=1;w<=k+c;w++)
                if(dp[v][w]>dp[v][u]+dp[u][w])
                    dp[v][w]=dp[v][u]+dp[u][w];

}
void Init_Flow(int mid)
{
    memset(f,0,sizeof(f));
    for(int i=1;i<=k;i++)
        f[0][i]=m;
    for(int i=1;i<=k;i++)
        for(int j=k+1;j<=k+c;j++)
            if(dp[i][j]<=mid)f[i][j]=1;
    for(int i=k+1;i<=k+c;i++)
        f[i][k+c+1]=1;
}
int Max_Flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        int mini=inf;
        memset(pre,-1,sizeof(pre));
        pre[s]=0;
        queue<int>Q;Q.push(s);
        while(!Q.empty()&&pre[t]==-1)
        {
            int j=Q.front();Q.pop();
            for(int i=1;i<=k+c+1;i++)
                if(pre[i]==-1&&f[j][i]>0)
                {
                    pre[i]=j;
                    if(f[j][i]<mini)mini=f[j][i];
                    Q.push(i);
                }
        }
        if(pre[t]==-1)return flow;
        for(int i=t;i!=s;i=pre[i])
        {
            f[pre[i]][i]-=mini;
            f[i][pre[i]]+=mini;
        }
        flow+=mini;
    }
}
int Binary_Search()
{
    int max=-1;
    for(int i=1;i<=k;i++)
    {
        for(int j=k+1;j<=k+c;j++)
        {
            //printf("%d ",dp[i][j]);
            max=max>dp[i][j]?max:dp[i][j];
        }
        //printf("\n");
    }
    int h=max,l=0,mid;
    //printf("%d\n",max);
    while(l<=h){
        mid=(h+l)/2;
        Init_Flow(mid);
        int temp=Max_Flow(0,k+c+1);
        //printf("mid: %d temp:%d \n",mid,temp);
        if(temp==c)
            h=mid-1;
        else
            l=mid+1;
    }
    return l;
}

int main()
{
    while(scanf("%d%d%d",&k,&c,&m)!=EOF)
    {
        for(int i=1;i<=k+c;i++)
        {
            for(int j=1;j<=k+c;j++)
            {
                scanf("%d",map[i]+j);
                if(i!=j&&map[i][j]==0)
                    map[i][j]=inf;
            }
        }
        Short_Path_Floyd();
        printf("%d\n",Binary_Search());
    }
    return 0;
}
