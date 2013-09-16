#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

const int inf = 1000000000;
struct node{double x,y;}nod[120];
int n,c[300][300],f[300][300],pre[300],kk[120],wi[120],ans[120];
inline double Distance(int i,int j)
{
    double ax=nod[i].x-nod[j].x;
    double by=nod[i].y-nod[j].y;
    return sqrt(ax*ax+by*by);
}
int max_flow(int s,int t)
{
    int flow=0;
    memset(f,0,sizeof(f));
    while(1)
    {
        int mini=inf;
        queue<int>Q;
        memset(pre,-1,sizeof(pre));
        Q.push(s);
        while(!Q.empty()&&pre[t]==-1)
        {
            int i=Q.front();Q.pop();
            for(int j=0;j<=2*n;j++)
            {
                if(pre[j]==-1&&c[i][j]>f[i][j])
                {
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1){
            //printf("flow %d\n",flow);
            return flow;
        }
        for(int i=t;i!=s;i=pre[i])
            if(mini>c[pre[i]][i]-f[pre[i]][i])
                mini=c[pre[i]][i]-f[pre[i]][i];
        flow+=mini;
        for(int i=t;i!=s;i=pre[i])
        {
            f[pre[i]][i]+=mini;
            f[i][pre[i]]-=mini;
        }
    }
}
int main()
{
    int nca,sum;
    scanf("%d",&nca);
    while(nca--)
    {
        double R;sum=0;
        scanf("%d%lf",&n,&R);
        for(int i=1;i<=n;i++)
            scanf("%lf%lf%d%d",&nod[i].x,&nod[i].y,wi+i,kk+i);
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            sum+=wi[i];
            for(int j=i+1;j<=n;j++)
                if(Distance(i,j)<=R)
                    c[2*i][2*j-1]=c[2*j][2*i-1]=inf;
            c[0][2*i-1]=wi[i];
            c[2*i-1][2*i]=kk[i];
        }
        int k=0;
        for(int i=1;i<=n;i++)
        {
            if(max_flow(0,2*i-1)==sum)ans[k++]=i-1;
        }
        if(k==0)puts("-1");
        else{
            for(int i=0;i<k;i++)
                printf("%d ",ans[i]);
            puts("");
        }
    }
    return 0;
}
