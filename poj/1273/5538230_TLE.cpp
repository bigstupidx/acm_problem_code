
#include<iostream>
#include<queue>
#include<string.h>
#define N 205
using namespace std;

int c[N][N],f[N][N];
int v[N],pre[N],n;

int Max_Flow()
{
    int ans=0;
    memset(f,0,sizeof(f));
    while(1)
    {
        int i,min;
        memset(v,0,sizeof(v));
        memset(pre,0,sizeof(pre));
        pre[1]=-1;
        min=100000000;
        queue<int>Q;
        Q.push(1);
        while(!Q.empty()&&pre[n]==0)
        {
            i=Q.front();Q.pop();
            v[i]=1;
            for(int j=1;j<=n;j++)
            {
                if(!v[j]&&c[i][j]>f[i][j])
                {
                    pre[j]=i;
                    if(min>c[i][j])min=c[i][j];
                    Q.push(j);
                }
            }
        }
        if(pre[n]==0)break;
        for(i=n;i!=-1;i=pre[i])
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
        int i,a,b,va;
        memset(c,0,sizeof(c));
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&va);
            c[a][b]+=va;
        }
        printf("%d\n",Max_Flow());
    }
    return 0;
}
