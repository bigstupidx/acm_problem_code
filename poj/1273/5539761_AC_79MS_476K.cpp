
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#define N 205
using namespace std;

int f[N][N],c[N][N];
int pre[N],n;

int main()
{
    int m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int a,b,va;
        memset(c,0,sizeof(c));
        memset(f,0,sizeof(f));
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&va);
            c[a][b]+=va;
        }
        int ans=0;
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
                    if(pre[j]==0)
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
            i=n;
            while(i!=0)
            {
                int j=abs(pre[i]);
                if(pre[i]>0) f[j][i]+=min;
                else f[i][j]-=min;
                i=j;
            }
            ans+=min;
        }
        printf("%d\n",ans);
    }
}
