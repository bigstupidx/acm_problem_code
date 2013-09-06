#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#define inf 100000000
#define ep 1e-7
using namespace std;
struct node{
    int x,y;
}nod[502];
int m,n,pre[120],v[120],flag[120];
double c[120][120],rr[120],cc[120];
void Max_Flow(int s,int t)
{
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
                if(pre[j]==-1&&c[i][j]-0>ep)
                {
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1)return ;
        for(int i=t;i!=s;i=pre[i])
            if(mini>c[pre[i]][i])mini=c[pre[i]][i];
        for(int i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
    }
}
void DFS(int s)
{
    v[s]=1;
    for(int i=1;i<=n+m+1;i++)
        if(!v[i]&&c[s][i]>0)DFS(i);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l;
        scanf("%d%d%d",&m,&n,&l);
        memset(c,0,sizeof(c));
        for(int i=1;i<=m;i++){
            scanf("%lf",&rr[i]);
            c[0][i]=rr[i];
        }
        for(int i=m+1;i<=m+n;i++){
            scanf("%lf",&cc[i-m]);
            c[i][n+m+1]=cc[i-m];
        }
        for(int i=0;i<l;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            c[x][y+m]=inf;
            nod[i].x=x; nod[i].y=y+m;
        }
        Max_Flow(0,m+n+1);
        memset(v,0,sizeof(v));  DFS(0);
        double sum=1.0;
        memset(flag,0,sizeof(flag));
        for(int i=0;i<l;i++)
        {
            if(!flag[nod[i].x]&&!v[nod[i].x]&&fabs(c[0][nod[i].x]-0)<ep)
            {
                flag[nod[i].x]=1;
                //printf("%d ",nod[i].x);
                sum*=rr[nod[i].x];
            }
            if(!flag[nod[i].y]&&v[nod[i].y]&&fabs(c[nod[i].y][n+m+1]-0)<ep)
            {
                flag[nod[i].y+m]=1;
                //printf("%d ",nod[i].y);
                sum*=cc[nod[i].y-m];
            }
        }
        //printf("\n");
        printf("%.4lf\n",sum);
    }
    return 0;
}
