#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000
using namespace std;
int map[240][240],dp[240][240];
int k,c,m,y[202],G_2[452][202],flag[202];

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
void Init_Match(int mid)
{
    memset(G_2,0,sizeof(G_2));
    for(int i=1;i<=k;i++)
        for(int j=k+1;j<=k+c;j++)
            if(dp[i][j]<=mid)
            {
                for(int ii=(i-1)*m+1;ii<=i*m;ii++)
                    G_2[ii][j-k]=1;
            }
    return ;
}
int Path(int s)
{
    for(int i=1;i<=c;i++)
    {
        if(!flag[i]&&G_2[s][i])
        {
            flag[i]=1;
            if(y[i]==0||Path(y[i]))
            {
                y[i]=s;
                return 1;
            }
        }
    }
    return 0;
}
int Max_Match()
{
    int ans=0;
    memset(y,0,sizeof(y));
    for(int i=1;i<=k*m;i++)
    {
        memset(flag,0,sizeof(flag));
        if(Path(i))ans++;
        if(ans==c)break;
    }
    return ans;
}
int Binary_Search()
{
    int maxi=-1;
    for(int i=1;i<=k;i++)
        for(int j=k+1;j<=k+c;j++)
            if(maxi<dp[i][j])maxi=dp[i][j];
    int h=maxi,l=0,mid;
    while(l<=h)
    {
        mid=(h+l)/2;
        Init_Match(mid);
        int temp=Max_Match();
        //printf("mid %d temp %d\n",mid,temp);
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
