
#include<iostream>
#include<queue>
#include<string.h>
#define N 205
using namespace std;

int f[N][N];
int v[N],pre[N],n;

int Max_Flow()
{
    int ans=0;
    while(1)
    {
        int min=10000000;
        queue<int>Q;
        memset(pre,0,sizeof(pre));
        memset(v,0,sizeof(v));
        Q.push(1);
        while(!Q.empty())
        {
            int i=Q.front();
            Q.pop();
            if(i==n)break;
            v[i]=1;
            for(int j=1;j<=n;j++)
            {
                if(!v[j]&&f[i][j]>0)
                {
                    pre[j]=i;
                    if(min>f[i][j])min=f[i][j];
                    Q.push(j);
                }
            }
        }
        if(pre[n]==0)break;
        for(int i=n;i!=0;i=pre[i])
        {
            f[pre[i]][i]-=min;
            f[i][pre[i]]+=min;
        }
        ans+=min;
    }
    return ans;
}
int main()
{
    int m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int i,a,b,va;
        memset(f,0,sizeof(f));
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&va);
            f[a][b]+=va;
        }
        printf("%d\n",Max_Flow());
    }
    return 0;
}
