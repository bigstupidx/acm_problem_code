
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#define N 205
using namespace std;

int f[N][N],c[N][N];
int pre[N],n;

int Max_Flow()
{
    int ans=0;
    memset(f,0,sizeof(f));
    while(1)
    {
        int i,min=1000000000;
        queue<int>Q;
        memset(pre,0,sizeof(pre));
        Q.push(1);
        while(!Q.empty()&&pre[n]==0)
        {
            i=Q.front();Q.pop();
            for(int j=2;j<=n;j++)
            {
                if(pre[j]==0&&c[i][j]>f[i][j])
                {
                    if(min>c[i][j]-f[i][j])
                        min=c[i][j]-f[i][j];
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[n]==0)break;
        for(i=n;i!=0;i=pre[i])
        {
            f[pre[i]][i]+=min;
            f[i][pre[i]]-=min;
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
        int a,b,va;
        memset(c,0,sizeof(c));
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&va);
            c[a][b]+=va;
        }
        printf("%d\n",Max_Flow());
    }
}
