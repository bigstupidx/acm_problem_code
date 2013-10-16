
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#define N 205
using namespace std;

int f[N][N],c[N][N];
int v[N],pre[N],n;

int Max_Flow()
{
    int ans=0;
    memset(f,0,sizeof(f));
    while(1)
    {
        int i,min=1000000000;
        queue<int>Q;
        memset(pre,0,sizeof(pre));
        memset(v,0,sizeof(v));
        Q.push(1);
        while(!Q.empty()&&pre[n]==0){
            i=Q.front();Q.pop();
            v[i]=1;
            for(int j=2;j<=n;j++)
            {
                if(!v[j])
                {
                    if(c[i][j]>f[i][j])
                    {
                        if(min>c[i][j]-f[i][j])
                            min=c[i][j]-f[i][j];
                        pre[j]=i;
                        Q.push(j);
                    }
                    else if(f[j][i]>0)
                    {
                        pre[j]=-1*i;
                        if(min>f[j][i])min=f[j][i];
                        Q.push(j);
                    }
                }
            }
        }
        if(pre[n]==0)break;
        for(i=n;i!=0;i=abs(pre[i]))
        {
            int j=abs(pre[i]);
            if(pre[i]>0)
                f[j][i]+=min;
            else
                f[i][j]-=min;
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
